#include "task_a.h"
#include <mcpp/mcpp.h>
#include <vector>
#include <iostream>
#include <random>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <thread>
#include <atomic> 


// Overlap check between two plots
bool plots_overlap(const Plot &a, const Plot &b) {
    return !(a.bound.x < b.origin.x || a.origin.x > b.bound.x ||
             a.bound.z < b.origin.z || a.origin.z > b.bound.z);
}

// Validating plot based on terrain
bool is_valid_plot(mcpp::MinecraftConnection &mc,
                   const Plot &plot,
                   int plot_border,
                   const std::vector<Plot> &existing) { 
    int water = 0, total = 0;
    int minY = 9999, maxY = -9999;

    mcpp::HeightMap heights = mc.getHeights(
        {plot.origin.x, plot.origin.z},
        {plot.bound.x - 1, plot.bound.z - 1});

    for (int x = plot.origin.x; x < plot.bound.x; ++x) {
        for (int z = plot.origin.z; z < plot.bound.z; ++z) {
            int y = heights.get_worldspace({x, z});
            total++;

            auto block = mc.getBlock({x, y - 1, z});
            if (block.id == 8 || block.id == 9)
                water++;

            minY = std::min(minY, y);
            maxY = std::max(maxY, y);
        }
    }

    if ((float)water / total > 0.15) return false;
    if (maxY - minY > 15) return false;

    for (const auto &p : existing)
        if (plots_overlap(p, plot))
            return false;

    return true;
}

// Finding valid plots 
std::vector<Plot> find_plots(mcpp::MinecraftConnection &mc,
                             const mcpp::Coordinate &village_center,
                             int village_size,
                             int plot_border) {
    std::vector<Plot> plots;
    if (village_size < 20) return plots;

    std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<int> sizeDist(14, 20);

    // Leaves 3 blocks of margin from wall
    int half = village_size / 2 - 3;
    int minX = village_center.x - half;
    int minZ = village_center.z - half;
    int maxX = village_center.x + half;
    int maxZ = village_center.z + half;

    std::uniform_int_distribution<int> xDist(minX, maxX);
    std::uniform_int_distribution<int> zDist(minZ, maxZ);

    int attempts = 0;
    int targetPlots = std::max(1, village_size / 50);

    while (attempts < 1000 && (int)plots.size() < targetPlots) {
        attempts++;

        // Randomize size (slight bias toward smaller for better fitting)
        int s = sizeDist(rng);
        if (rng() % 3 == 0) s = 14 + (rng() % 7);  // add more variability

        int x = xDist(rng);
        int z = zDist(rng);

        // Skip if plot goes outside the walls
        if (x + s >= maxX - 1 || z + s >= maxZ - 1)
            continue;

        // Get average ground height for this plot area
        mcpp::HeightMap heights = mc.getHeights({x, z}, {x + s, z + s});
        int y = heights.get_worldspace({x + s / 2, z + s / 2});

        Plot p({x, y, z}, {x + s, y, z + s}, {x + s / 2, y, z + s -1});

        // Validate terrain and overlap
        if (is_valid_plot(mc, p, plot_border, plots)) {
            plots.push_back(p);
            
        }
    }

    if (plots.empty())
        std::cerr << "No valid plots found." << std::endl;
    else
        std::cout << "\tFound " << plots.size() << " valid plot(s) inside walls\n";

    return plots;
}


// Terraforming plots (Attempt 13: using getHeights and setBlocks for faster result)
void terraform(mcpp::MinecraftConnection &mc,
               const std::vector<Plot> &plots,
               int plot_border,
               const mcpp::Coordinate &village_center,
               int village_size) {
    if (plots.empty()) {
        std::cerr << "No valid plots found.\n";
        return;
    }

    std::vector<std::thread> threads;

    int half = village_size / 2 - 3;
    int minX = village_center.x - half;
    int maxX = village_center.x + half;
    int minZ = village_center.z - half;
    int maxZ = village_center.z + half;

    std::atomic<int> finished{0};

    auto work = [&](const Plot &plot, int index) {
        int x1 = std::max(plot.origin.x, minX + 1);
        int x2 = std::min(plot.bound.x, maxX - 1);
        int z1 = std::max(plot.origin.z, minZ + 1);
        int z2 = std::min(plot.bound.z, maxZ - 1);

        // Expand sampling area slightly for smoothing
        int sx1 = std::max(minX, x1 - plot_border - 2);
        int sz1 = std::max(minZ, z1 - plot_border - 2);
        int sx2 = std::min(maxX, x2 + plot_border + 2);
        int sz2 = std::min(maxZ, z2 + plot_border + 2);

        // Clamp sampling window (<=80x80)
        sx2 = std::min(sx2, sx1 + 79);
        sz2 = std::min(sz2, sz1 + 79);

        mcpp::HeightMap heights = mc.getHeights({sx1, sz1}, {sx2, sz2});

        // Compute average height using coarse sampling
        long long totalH = 0;
        int count = 0;
        for (int x = x1; x < x2; x += 2)
            for (int z = z1; z < z2; z += 2)
                totalH += heights.get_worldspace({x, z}), count++;
        int flatY = totalH / std::max(1, count);

        // Flattens ground in 16x16 batches
        for (int bx = x1; bx <= x2; bx += 16) {
            for (int bz = z1; bz <= z2; bz += 16) {
                int ex = std::min(bx + 15, x2);
                int ez = std::min(bz + 15, z2);

                mc.setBlocks({bx, flatY - 5, bz}, {ex, flatY - 1, ez}, mcpp::Blocks::DIRT);
                mc.setBlocks({bx, flatY, bz}, {ex, flatY, ez}, mcpp::Blocks::GRASS);
                mc.setBlocks({bx, flatY + 1, bz}, {ex, flatY + 60, ez}, mcpp::Blocks::AIR);

                // Short controlled delay per batch
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
            }
        }

        // Smooth slopes
        for (int x = std::max(minX, x1 - plot_border); x <= std::min(maxX, x2 + plot_border); ++x) {
            for (int z = std::max(minZ, z1 - plot_border); z <= std::min(maxZ, z2 + plot_border); ++z) {
                if (x >= x1 && x <= x2 && z >= z1 && z <= z2) continue;

                int dx = (x < x1) ? (x1 - x) : (x > x2 ? (x - x2) : 0);
                int dz = (z < z1) ? (z1 - z) : (z > z2 ? (z - z2) : 0);
                float dist = std::sqrt(dx * dx + dz * dz);
                if (dist > plot_border) continue;

                int h = heights.get_worldspace({x, z});
                float t = 1.0f - (dist / (plot_border + 0.001f));
                int targetY = std::round(h + (flatY - h) * t * 0.7f);

                if (targetY > h)
                    mc.setBlocks({x, h, z}, {x, targetY - 1, z}, mcpp::Blocks::DIRT);
                else if (targetY < h)
                    mc.setBlocks({x, targetY + 1, z}, {x, h, z}, mcpp::Blocks::AIR);

                mc.setBlock({x, targetY, z}, mcpp::Blocks::GRASS);
            }
        }

        std::cout << "\tPlot " << (index + 1) << " finished.\n";
        finished++;
    };

    // Launch threads for each plot
    for (size_t i = 0; i < plots.size(); ++i) {
        threads.emplace_back(work, std::cref(plots[i]), i);
        for (auto &t : threads) t.join();
        threads.clear();

        // Small delay between plots
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

    mc.postToChat("Terraforming complete.");
    std::cout << "\tTerraforming complete.\n";
}

// place_wall
void place_wall(mcpp::MinecraftConnection &mc,
                const mcpp::Coordinate &village_center,
                int village_size) {
    if (village_size < 10) return;

    const int MIN_STONE = 4;
    const int SLAB_ON_TOP = 1;
    const int REQUIRED_GAP = 2;
    const int SAMPLE_OFFSET = 2;
    const int MAX_SLOPE = 2;

    int half = village_size / 2;
    int x1 = village_center.x - half;
    int x2 = village_center.x + half;
    int z1 = village_center.z - half;
    int z2 = village_center.z + half;

    // Expand slightly 
    int sx = std::min(x1, x2) - SAMPLE_OFFSET;
    int sz = std::min(z1, z2) - SAMPLE_OFFSET;
    int ex = std::max(x1, x2) + SAMPLE_OFFSET;
    int ez = std::max(z1, z2) + SAMPLE_OFFSET;

    // Grab one large heightmap
    mcpp::HeightMap hm = mc.getHeights({sx, sz}, {ex, ez});

    auto is_tree_like = [&](int id) -> bool {
        return (id == 17 || id == 18 || id == 162 || id == 161 || id == 106);
    };

    // Find real ground, skipping air/leaves/logs
    auto find_ground = [&](int x, int z) -> int {
        int y = hm.get_worldspace({x, z}); // start from terrain height
        int attempts = 0;

        while (y > 0 && attempts < 6) {  // only check up to 6 blocks below
            auto below = mc.getBlock({x, y - 1, z});
            if (below.id == 0 || is_tree_like(below.id)) { // skip air/leaves/logs
                y--;
                attempts++;
                continue;
            }
            break;
        }

        // Maximum ground level is y-1
        return std::max(0, y - 1);
    };

    auto build_wall_segment = [&](int x1, int z1, int x2, int z2, bool alongX, int dirX, int dirZ) {
        int len = alongX ? std::abs(x2 - x1) : std::abs(z2 - z1);
        int step = (alongX ? ((x2 >= x1) ? 1 : -1) : ((z2 >= z1) ? 1 : -1));

        int prevTopY = -9999;

        for (int i = 0; i <= len; i++) {
            int x = alongX ? x1 + i * step : x1;
            int z = alongX ? z1 : z1 + i * step;

            int groundY = find_ground(x, z);

            int outerX = x + dirX * SAMPLE_OFFSET;
            int outerZ = z + dirZ * SAMPLE_OFFSET;
            int innerX = x - dirX * SAMPLE_OFFSET;
            int innerZ = z - dirZ * SAMPLE_OFFSET;

            int outerH = hm.get_worldspace({outerX, outerZ});
            int innerH = hm.get_worldspace({innerX, innerZ});

            int surroundingMax = std::max(outerH, innerH);
            int minimalTopFromGround = groundY + MIN_STONE;
            int minimalTopFromSurround = surroundingMax + REQUIRED_GAP;
            int topY = std::max(minimalTopFromGround, minimalTopFromSurround);

            // Smooth slope transitions
            if (prevTopY != -9999) {
                if (topY > prevTopY + MAX_SLOPE) topY = prevTopY + MAX_SLOPE;
                else if (topY < prevTopY - MAX_SLOPE) topY = prevTopY - MAX_SLOPE;
            }
            prevTopY = topY;

            // Build 3 stone + slab
            int slabY = topY + SLAB_ON_TOP;
            mc.setBlocks({x, groundY + 1, z}, {x, topY, z}, mcpp::Blocks::STONE);
            mc.setBlock({x, slabY, z}, mcpp::Blocks::STONE_SLAB);

            // Small delay every few columns (prevents API overload)
            if (i % 20 == 0)
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    };

    // Parallelize opposite sides for speed
    build_wall_segment(x1, z1, x2, z1, true, 0, -1);  // north
    build_wall_segment(x1, z2, x2, z2, true, 0, 1);   // south
    build_wall_segment(x1, z1, x1, z2, false, -1, 0); // west
    build_wall_segment(x2, z1, x2, z2, false, 1, 0);  // east

    mc.postToChat("Village walls built.");
    std::cout << "\tWalls built.\n";
}

/// Waypoint Generation
std::vector<mcpp::Coordinate> generate_waypoints(
    const std::vector<Plot> &plots,
    const mcpp::Coordinate &village_center,
    int village_size)
{
    std::vector<mcpp::Coordinate> waypoints;

    if (plots.empty()) {
        std::cerr << "No plots provided for waypoint generation.\n";
        return waypoints;
    }

    // Minimum and maximum allowed waypoint counts
    int minWaypoints = std::max(1, static_cast<int>(plots.size() / 5));
    int maxWaypoints = std::max(minWaypoints, static_cast<int>(plots.size() / 3) + 1);

    // Sort plots by distance from village center (using p.center)
    auto distSq = [&](const Plot &p) {
        int dx = p.center.x - village_center.x;
        int dz = p.center.z - village_center.z;
        return dx * dx + dz * dz;
    };

    std::vector<Plot> sorted = plots;
    std::sort(sorted.begin(), sorted.end(),
              [&](const Plot &a, const Plot &b) { return distSq(a) < distSq(b); });

    // Group neighboring plots into sets of three
    for (size_t i = 0; i < sorted.size(); i += 3) {
        size_t remaining = sorted.size() - i;
        size_t groupSize = (remaining <= 2 && !waypoints.empty()) ? remaining + 3 : std::min<size_t>(3, remaining);
        size_t end = std::min(i + groupSize, sorted.size());

        std::vector<Plot> group(sorted.begin() + i, sorted.begin() + end);

        // Compute centroid of group
        int sumX = 0, sumY = 0, sumZ = 0;
        for (auto &p : group) {
            sumX += p.center.x;
            sumY += p.center.y;
            sumZ += p.center.z;
        }

        int cx = sumX / static_cast<int>(group.size());
        int cy = sumY / static_cast<int>(group.size());
        int cz = sumZ / static_cast<int>(group.size());

        // Check if the center is inside any plot 
        bool insidePlot = false;
        for (auto &p : plots) {
            if (cx >= p.origin.x && cx <= p.bound.x &&
                cz >= p.origin.z && cz <= p.bound.z) {
                insidePlot = true;
                break;
            }
        }

        // Add waypoint if valid
        if (!insidePlot)
            waypoints.push_back({cx, cy + 1, cz});

        if (static_cast<int>(waypoints.size()) >= maxWaypoints)
            break;
    }

    // Output
    if (waypoints.size() < static_cast<size_t>(minWaypoints)) {
        std::cerr << "Warning: Not enough valid waypoints (" << waypoints.size()
                  << " found, need at least " << minWaypoints << ").\n";
    } else {
        std::cout << "\tGenerated " << waypoints.size() << " waypoint(s).\n";
    }

    return waypoints;
}
