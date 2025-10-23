#include "task_b.h"
#include <iostream>

void build_buildings() {
    mcpp::MinecraftConnection mc;

    std::cout << "\t Building the exterior of the buildings..." << std::endl;
    std::cout << "\t Subdividing the interior..." << std::endl;
    std::cout << "\t Doing some interior decorating..." << std::endl;

    mcpp::Coordinate player = mc.getPlayerPosition();

    int length = 10; // x-direction
    int width = 8;   // z-direction
    int height = 6;  // y-direction

    int baseY = player.y - 1;

    int startX = player.x - (length / 2);
    int endX = player.x + (length / 2);
    int startZ = player.z - (width / 2);
    int endZ = player.z + (width / 2);

    // === FLOOR ===
    for (int x = startX; x <= endX; ++x) {
        for (int z = startZ; z <= endZ; ++z) {
            mc.setBlock(mcpp::Coordinate{x, baseY, z}, mcpp::Blocks::OAK_WOOD_PLANK);
        }
    }

    // === WALLS ===
    for (int y = baseY + 1; y <= baseY + height; ++y) {
        for (int x = startX; x <= endX; ++x) {
            for (int z = startZ; z <= endZ; ++z) {
                bool isEdge = (x == startX || x == endX || z == startZ || z == endZ);
                if (isEdge) {
                    mc.setBlock(mcpp::Coordinate{x, y, z}, mcpp::Blocks::BRICKS);
                }
            }
        }
    }

    // === ROOF ===
    for (int x = startX; x <= endX; ++x) {
        for (int z = startZ; z <= endZ; ++z) {
            mc.setBlock(mcpp::Coordinate{x, baseY + height + 1, z}, mcpp::Blocks::OAK_WOOD_PLANK);
        }
    }

    std::cout << "\t Built a house at player location: (" 
              << player.x << ", " << player.y << ", " << player.z << ")" << std::endl;
}
