#include "task_b.h"
#include <mcpp/mcpp.h>
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>

// Room structure for bounds
struct Room {
    int x1, z1, x2, z2;
};

// Helper to place a functional Oak Door
void placeDoor(mcpp::MinecraftConnection &mc, int x, int y, int z) {
    mc.setBlock({x, y, z}, mcpp::Blocks::AIR);
    mc.setBlock({x, y + 1, z}, mcpp::Blocks::AIR);
    mc.setBlock({x, y, z}, mcpp::Blocks::OAK_DOOR_BLOCK);
}

// Recursive subdivision (Checks Door Placements)
void subdivideRoom(
    mcpp::MinecraftConnection &mc,
    int x1, int z1, int x2, int z2,
    int baseY, int height,
    std::mt19937 &rng,
    std::vector<Room> &rooms,
    std::vector<std::pair<int, int>> &doors // Track door positions
) {
    int width = x2 - x1;
    int depth = z2 - z1;

    // Stop subdividing when room is small enough
    if (width <= 8 && depth <= 8) {
        rooms.push_back({x1, z1, x2, z2});
        return;
    }

    std::uniform_int_distribution<int> axisDist(0, 1);
    bool splitVertical = axisDist(rng);

    if (width < 8) splitVertical = false;
    if (depth < 8) splitVertical = true;

    int attempts = 0;
    const int maxAttempts = 10;

    if (splitVertical) {
        std::uniform_int_distribution<int> splitDist(x1 + 4, x2 - 4);
        int splitX;

        // split line that does not intersect existing doors
        do {
            splitX = splitDist(rng);
            bool conflicts = false;

            for (auto &[dx, dz] : doors) {
                if (dx == splitX && dz >= z1 && dz <= z2) {
                    conflicts = true;
                    break;
                }
            }

            if (!conflicts) break;
            attempts++;
        } while (attempts < maxAttempts);

        if (attempts >= maxAttempts) {
            rooms.push_back({x1, z1, x2, z2});
            return;
        }

        // Build dividing wall
        for (int y = baseY + 1; y <= baseY + height - 1; ++y)
            for (int z = z1 + 1; z <= z2 - 1; ++z)
                mc.setBlock({splitX, y, z}, mcpp::Blocks::BRICKS);

        // Add connecting door
        int doorZ = std::uniform_int_distribution<int>(z1 + 2, z2 - 2)(rng);
        placeDoor(mc, splitX, baseY + 1, doorZ);
        doors.push_back({splitX, doorZ});

        // Recurse
        subdivideRoom(mc, x1, z1, splitX, z2, baseY, height, rng, rooms, doors);
        subdivideRoom(mc, splitX, z1, x2, z2, baseY, height, rng, rooms, doors);
    } 
    else {
        std::uniform_int_distribution<int> splitDist(z1 + 4, z2 - 4);
        int splitZ;

        // Split line that does not intersect existing doors
        do {
            splitZ = splitDist(rng);
            bool conflicts = false;

            for (auto &[dx, dz] : doors) {
                if (dz == splitZ && dx >= x1 && dx <= x2) {
                    conflicts = true;
                    break;
                }
            }

            if (!conflicts) break;
            attempts++;
        } while (attempts < maxAttempts);

        if (attempts >= maxAttempts) {
            rooms.push_back({x1, z1, x2, z2});
            return;
        }

        // Build dividing wall 
        for (int y = baseY + 1; y <= baseY + height - 1; ++y)
            for (int x = x1 + 1; x <= x2 - 1; ++x)
                mc.setBlock({x, y, splitZ}, mcpp::Blocks::BRICKS);

        // Add connecting door
        int doorX = std::uniform_int_distribution<int>(x1 + 2, x2 - 2)(rng);
        placeDoor(mc, doorX, baseY + 1, splitZ);
        doors.push_back({doorX, splitZ});

        // Recurse
        subdivideRoom(mc, x1, z1, x2, splitZ, baseY, height, rng, rooms, doors);
        subdivideRoom(mc, x1, splitZ, x2, z2, baseY, height, rng, rooms, doors);
    }
}

// Furnish Rooms
void furnishRoom(mcpp::MinecraftConnection &mc, const Room &r, int baseY, std::mt19937 &rng) {
    std::vector<std::string> themes = {"Bedroom", "Kitchen", "Living", "Bathroom", "Study"};
    std::uniform_int_distribution<int> themeDist(0, (int)themes.size() - 1);
    std::string theme = themes[themeDist(rng)];

    int centerX = (r.x1 + r.x2) / 2;
    int centerZ = (r.z1 + r.z2) / 2;
    int y = baseY + 1;

    if (theme == "Bedroom") {
    mc.setBlock({centerX, y, centerZ}, mcpp::Blocks::BED);
    mc.setBlock({centerX + 1, y, centerZ}, mcpp::Blocks::BED);
    mc.setBlock({centerX, y, centerZ + 1}, mcpp::Blocks::BLUE_CARPET);

    } 
    else if (theme == "Kitchen") {
        mc.setBlock({centerX, y, centerZ}, mcpp::Blocks::CAULDRON);
        mc.setBlock({centerX + 1, y, centerZ}, mcpp::Blocks::IRON_BLOCK);
        mc.setBlock({centerX + 1, y + 1, centerZ}, mcpp::Blocks::IRON_BLOCK);
        mc.setBlock({centerX, baseY, centerZ}, mcpp::Blocks::IRON_BLOCK);
    }
    else if (theme == "Living") {
        mc.setBlock({centerX, y, centerZ}, mcpp::Blocks::RED_CARPET);
        mc.setBlock({centerX + 1, y, centerZ}, mcpp::Blocks::BOOKSHELF);
    }
    else if (theme == "Bathroom") {
        mc.setBlock({centerX, y, centerZ}, mcpp::Blocks::CAULDRON);
        mc.setBlock({centerX + 1, y, centerZ}, mcpp::Blocks::QUARTZ_BLOCK);
        mc.setBlock({centerX, baseY, centerZ}, mcpp::Blocks::QUARTZ_BLOCK);
    }
    else if (theme == "Study") {
        mc.setBlock({centerX, y, centerZ}, mcpp::Blocks::DARK_OAK_FENCE);
        mc.setBlock({centerX, y + 1, centerZ}, mcpp::Blocks::CHEST);
        mc.setBlock({centerX + 1, y, centerZ}, mcpp::Blocks::CRAFTING_TABLE);
    }
}

// Build the entire house
void build_buildings(mcpp::MinecraftConnection &mc, const std::vector<Plot> &plots, bool testmode) {
    if (plots.empty()) {
        std::cout << "\tNo plots provided.\n";
        return;
    }

    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));

    for (size_t i = 0; i < plots.size(); ++i) {
        const Plot &p = plots[i];
        if (testmode) rng.seed((unsigned int)i);

        int height = testmode ? std::min<int>(6 + i, 20)
                              : std::uniform_int_distribution<int>(6, 20)(rng);

        int startX = p.origin.x + 1, endX = p.bound.x - 1;
        int startZ = p.origin.z + 1, endZ = p.bound.z - 1;

        mcpp::HeightMap heights = mc.getHeights({startX, startZ}, {endX, endZ});
        int baseY = heights.get_worldspace({(startX + endX) / 2, (startZ + endZ) / 2});

        // Floor
        mc.setBlocks({startX, baseY, startZ}, {endX, baseY, endZ}, mcpp::Blocks::OAK_WOOD_PLANK);

        // Outer walls
        for (int y = baseY + 1; y <= baseY + height; ++y) {
            mc.setBlocks({startX, y, startZ}, {endX, y, startZ}, mcpp::Blocks::BRICKS);
            mc.setBlocks({startX, y, endZ}, {endX, y, endZ}, mcpp::Blocks::BRICKS);
            mc.setBlocks({startX, y, startZ}, {startX, y, endZ}, mcpp::Blocks::BRICKS);
            mc.setBlocks({endX, y, startZ}, {endX, y, endZ}, mcpp::Blocks::BRICKS);
        }

        // Roof
        if (height > 10) {
            mc.setBlocks({startX, baseY + height + 1, startZ},
                         {endX, baseY + height + 1, endZ},
                         mcpp::Blocks::OAK_WOOD_PLANK);

            int glowY = baseY + 9;
            mc.setBlocks({startX + 1, glowY, startZ + 1},
                         {endX - 1, glowY, endZ - 1},
                         mcpp::Blocks::GLOWSTONE);
        } else {
            mc.setBlocks({startX, baseY + height + 1, startZ},
                         {endX, baseY + height + 1, endZ},
                         mcpp::Blocks::OAK_WOOD_PLANK);

            mc.setBlocks({startX + 1, baseY + height, startZ + 1},
                         {endX - 1, baseY + height, endZ - 1},
                         mcpp::Blocks::GLOWSTONE);
        }

        // Main door
        int doorX = p.enterance.x;
        int doorZ = p.enterance.z;
        placeDoor(mc, doorX, baseY + 1, doorZ);

        // Subdivide with door tracking
        std::vector<Room> rooms;
        std::vector<std::pair<int, int>> doors;
        doors.push_back({doorX, startZ}); // Track main door

        subdivideRoom(mc, startX, startZ, endX, endZ, baseY, height, rng, rooms, doors);

        // Furnish rooms
        for (auto &r : rooms) furnishRoom(mc, r, baseY, rng);

        std::cout << "\tHouse " << i + 1 << ": " << rooms.size()
                  << " rooms, doors connected and furnished.\n";
    }

    mc.postToChat("All houses built with connected rooms and furniture!");
}
