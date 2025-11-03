#include "task_c.h"
#include "paths.h"
#include <queue>
#include <limits>
#include <cmath>

// Helper: squared distance on XZ plane
static long dist_sq_xz(const mcpp::Coordinate &a, const mcpp::Coordinate &b) {
	long dx = a.x - b.x;
	long dz = a.z - b.z;
	return dx*dx + dz*dz;
}

// Lay a path in the world using the provided path coordinates.
static void lay_path(mcpp::MinecraftConnection &mc, const std::vector<mcpp::Coordinate> &path) {
	if (path.empty()) return;
	for (const auto &c : path) {
		// place grass at ground and clear above a bit
		mc.setBlock({c.x, c.y, c.z}, mcpp::Blocks::GRAVEL);
		mc.setBlocks({c.x, c.y + 1, c.z}, {c.x, c.y + 3, c.z}, mcpp::Blocks::AIR);
	}
}

void connect_waypoints(mcpp::MinecraftConnection& mc, const std::vector<Plot>& plots, const std::vector<mcpp::Coordinate>& waypoints) {
	if (waypoints.empty()) return;

	std::vector<bool> connected(waypoints.size(), false);
	// Start from first waypoint
	connected[0] = true;
	int connectedCount = 1;

	while (connectedCount < (int)waypoints.size()) {
		long bestDist = std::numeric_limits<long>::max();
		int bestFrom = -1;
		int bestTo = -1;

		for (size_t i = 0; i < waypoints.size(); ++i) {
			if (!connected[i]) continue;
			for (size_t j = 0; j < waypoints.size(); ++j) {
				if (connected[j]) continue;
				long d = dist_sq_xz(waypoints[i], waypoints[j]);
				if (d < bestDist) {
					bestDist = d;
					bestFrom = (int)i;
					bestTo = (int)j;
				}
			}
		}

		if (bestFrom == -1 || bestTo == -1) break; // nothing found

		// Find path using BFS
		auto path = find_path(mc, waypoints[bestFrom], waypoints[bestTo], plots);
		if (path.empty()) {
			std::cerr << "Warning: could not find path between waypoints " << bestFrom << " and " << bestTo << "\n";
		} else {
			lay_path(mc, path);
		}

		connected[bestTo] = true;
		connectedCount++;
	}
}

void connect_buildings(mcpp::MinecraftConnection& mc, const std::vector<Plot>& plots, const std::vector<mcpp::Coordinate>& waypoints) {
	if (waypoints.empty()) return;

	for (const auto &plot : plots) {
		mcpp::Coordinate entrance = plot.entrance;
		// find nearest waypoint
		int bestIdx = -1;
		long bestD = std::numeric_limits<long>::max();
		for (size_t i = 0; i < waypoints.size(); ++i) {
			long d = dist_sq_xz(entrance, waypoints[i]);
			if (d < bestD) { bestD = d; bestIdx = (int)i; }
		}

		if (bestIdx == -1) continue;

		auto path = find_path(mc, entrance, waypoints[bestIdx], plots);
		if (path.empty()) {
			// Try fallback: attempt from adjacent tiles around the entrance (so road can start just outside plot)
			const int neigh[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
			// Score neighbors by (outside_plot ? 0 : 1) and distance to waypoint; lower is better.
			int bestN = -1;
			long bestScoreD = std::numeric_limits<long>::max();
			for (int n = 0; n < 4; ++n) {
				int nx = entrance.x + neigh[n][0];
				int nz = entrance.z + neigh[n][1];
				bool inside = false;
				for (size_t pi = 0; pi < plots.size(); ++pi) {
					const Plot &pp = plots[pi];
					if (nx > pp.origin.x && nx < pp.bound.x && nz > pp.origin.z && nz < pp.bound.z) { inside = true; break; }
				}
				long d = (nx - waypoints[bestIdx].x) * (long)(nx - waypoints[bestIdx].x) + (nz - waypoints[bestIdx].z) * (long)(nz - waypoints[bestIdx].z);
				long score = d + (inside ? 1000000000L : 0L);
				if (score < bestScoreD) { bestScoreD = score; bestN = n; }
			}
			bool connected = false;
			if (bestN != -1) {
				int nx = entrance.x + neigh[bestN][0];
				int nz = entrance.z + neigh[bestN][1];
				mcpp::Coordinate neighbor = {nx, entrance.y, nz};
				auto npath = find_path(mc, neighbor, waypoints[bestIdx], plots);
				if (!npath.empty()) {
					std::vector<mcpp::Coordinate> full;
					full.push_back(entrance);
					for (size_t k = 0; k < npath.size(); ++k) full.push_back(npath[k]);
					lay_path(mc, full);
					connected = true;
				}
			}
			if (!connected) {
				std::cerr << "Warning: could not connect building at (" << entrance.x << "," << entrance.z << ") to waypoint " << bestIdx << "\n";
			}
		} else {
			lay_path(mc, path);
		}
	}
}