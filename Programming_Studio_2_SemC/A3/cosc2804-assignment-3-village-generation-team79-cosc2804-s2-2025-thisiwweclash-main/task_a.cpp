#include "task_a.h"
#include <mcpp/mcpp.h>
#include <vector>
#include <iostream>
#include <random>
#include <cmath>
#include <ctime>


// Helper: check if two plots overlap
bool plots_overlap(const Plot &a, const Plot &b) {
    return !(a.bound.x < b.origin.x || a.origin.x > b.bound.x ||
             a.bound.z < b.origin.z || a.origin.z > b.bound.z);
}

// Helper: check if plot is valid
bool is_valid_plot(mcpp::MinecraftConnection &mc,
                   const Plot &plot,
                   int plot_border,
                   const std::vector<Plot> &existing) {

    int water = 0, total = 0;
    int minY = 9999, maxY = -9999;

    for (int x = plot.origin.x; x < plot.bound.x; ++x) {
        for (int z = plot.origin.z; z < plot.bound.z; ++z) {
            int y = mc.getHeight({x, z});
            total++;
            auto block = mc.getBlock({x, y - 1, z});
            if (block.id == 8 || block.id == 9)  // water blocks
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

// Find valid plots
std::vector<Plot> find_plots(mcpp::MinecraftConnection &mc, int village_size, int plot_border) {
    std::vector<Plot> plots;
    if (village_size < 20) return plots;

    std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<int> sizeDist(14, 20);

    mcpp::Coordinate player = mc.getPlayerPosition();
    int half = village_size / 2;
    int minX = player.x - half;
    int minZ = player.z - half;
    int maxX = player.x + half;
    int maxZ = player.z + half;

    std::uniform_int_distribution<int> xDist(minX, maxX);
    std::uniform_int_distribution<int> zDist(minZ, maxZ);

    int attempts = 0;
    while (attempts < 1000 && (int)plots.size() < std::max(1, village_size / 50)) {
        attempts++;
        int s = sizeDist(rng);
        int x = xDist(rng);
        int z = zDist(rng);
        int y = mc.getHeight({x, z});

        Plot p({x, y, z}, {x + s, y, z + s}, {x + s / 2, y, z + s / 2});
        if (is_valid_plot(mc, p, plot_border, plots))
            plots.push_back(p);
    }

    if (plots.empty())
        std::cerr << "No valid plots found after 1000 attempts!" << std::endl;
    else
        std::cout << "\t Found " << plots.size() << " valid plot(s)\n";

    return plots;
}

// Terraform plots (flatten and smooth edges)
void terraform(mcpp::MinecraftConnection &mc, const std::vector<Plot> &plots, int plot_border) {
    for (const auto &plot : plots) {
        // average height
        int totalH = 0, count = 0;
        for (int x = plot.origin.x; x < plot.bound.x; ++x)
            for (int z = plot.origin.z; z < plot.bound.z; ++z)
                totalH += mc.getHeight({x, z}), count++;
        int flatY = totalH / count;

        // flatten
        for (int x = plot.origin.x; x < plot.bound.x; ++x) {
            for (int z = plot.origin.z; z < plot.bound.z; ++z) {
                int h = mc.getHeight({x, z});
                if (h < flatY)
                    for (int y = h; y <= flatY; ++y) mc.setBlock({x, y, z}, mcpp::Blocks::DIRT);
                else if (h > flatY)
                    for (int y = h; y > flatY; --y) mc.setBlock({x, y, z}, mcpp::Blocks::AIR);
                mc.setBlock({x, flatY, z}, mcpp::Blocks::GRASS);
            }
        }

        // draw border in wool for visibility
        for (int x = plot.origin.x; x < plot.bound.x; ++x) {
            mc.setBlock({x, flatY + 1, plot.origin.z}, mcpp::Blocks::WHITE_WOOL);
            mc.setBlock({x, flatY + 1, plot.bound.z}, mcpp::Blocks::WHITE_WOOL);
        }
        for (int z = plot.origin.z; z < plot.bound.z; ++z) {
            mc.setBlock({plot.origin.x, flatY + 1, z}, mcpp::Blocks::WHITE_WOOL);
            mc.setBlock({plot.bound.x, flatY + 1, z}, mcpp::Blocks::WHITE_WOOL);
        }

        // smooth transition
        for (int x = plot.origin.x - plot_border; x < plot.bound.x + plot_border; ++x) {
            for (int z = plot.origin.z - plot_border; z < plot.bound.z + plot_border; ++z) {
                int dist = std::min(
                    std::min(std::abs(x - plot.origin.x), std::abs(x - plot.bound.x)),
                    std::min(std::abs(z - plot.origin.z), std::abs(z - plot.bound.z))
                );
                if (dist <= plot_border) {
                    int h = mc.getHeight({x, z});
                    float t = 1.0f - (float)dist / plot_border;
                    int newY = std::round(h + (flatY - h) * t);
                    mc.setBlock({x, newY, z}, mcpp::Blocks::GRASS);
                }
            }
        }
    }
}


// Build adaptive wall (for near mountains and stuff)
void place_wall(mcpp::MinecraftConnection &mc, mcpp::Coordinate player, int village_size) {
    if (village_size < 10) return;

    const int baseWallHeight = 4;   // Normal wall height
    const int safetyGap = 2;        // Extra height if terrain is close
    const int checkRadius = 2;      // How far to scan around each column
    const int maxStep = 1;          // Max allowed vertical change between adjacent columns
    const int maxExtraHeight = 3;   // Max extra height above base

    int half = village_size / 2;
    int x1 = player.x - half;
    int x2 = player.x + half;
    int z1 = player.z - half;
    int z2 = player.z + half;

    // Helper to calculate safe wall height
    auto calculateWallHeight = [&](int x, int z) {
        int groundY = mc.getHeight({x, z});
        int highestNearby = groundY;

        // Scan nearby terrain to check climbable spots
        for (int dx = -checkRadius; dx <= checkRadius; ++dx)
            for (int dz = -checkRadius; dz <= checkRadius; ++dz)
                highestNearby = std::max(highestNearby, mc.getHeight({x + dx, z + dz}));

        int diff = highestNearby - groundY;
        int height = baseWallHeight;

        // Raise only slightly if climbable terrain detected
        if (diff >= baseWallHeight - safetyGap)
            height = std::min(baseWallHeight + (diff - (baseWallHeight - safetyGap)) + 1,
                              baseWallHeight + maxExtraHeight);

        return std::make_pair(groundY, height);
    };

    // Function to safely build with smoothing
    auto buildSmoothWall = [&](int xStart, int xEnd, int zConst, bool alongX) {
        int prevTopY = -9999;
        for (int i = xStart; i <= xEnd; ++i) {
            int x = alongX ? i : zConst;
            int z = alongX ? zConst : i;

            auto [groundY, height] = calculateWallHeight(x, z);
            int topY = groundY + height;

            // Smooth transitions between columns
            if (prevTopY != -9999 && std::abs(topY - prevTopY) > maxStep)
                topY = prevTopY + ((topY > prevTopY) ? maxStep : -maxStep);

            for (int y = groundY; y <= topY; ++y)
                mc.setBlock({x, y, z}, mcpp::Blocks::STONE);

            prevTopY = topY;
        }
    };

    // Build walls with smoothing in all directions
    buildSmoothWall(x1, x2, z1, true);   // North edge
    buildSmoothWall(x1, x2, z2, true);   // South edge
    buildSmoothWall(z1, z2, x1, false);  // West edge
    buildSmoothWall(z1, z2, x2, false);  // East edge

    std::cout << "\t Smooth adaptive wall placed successfully around player (" 
              << player.x << ", " << player.z << ")\n";
}





