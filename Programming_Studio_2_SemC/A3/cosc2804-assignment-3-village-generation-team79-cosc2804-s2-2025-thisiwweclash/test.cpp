#include <mcpp/mcpp.h>
int main() {
    mcpp::MinecraftConnection mc;
    mcpp::Coordinate pos = mc.getPlayerTile();
    mc.setBlock(pos, mcpp::Blocks::DIAMOND_BLOCK);
    return 0;
}
