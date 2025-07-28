#include <iostream>
#include <string>

#include "mcpp/mcpp.h"

using namespace std;


int main(void) {

    cout << "hello from main" << endl;
    string name = "Vuong";

    mcpp::MinecraftConnection mc;

    mc.doCommand("time set day");
    mc.postToChat("hoho");


    // mcpp::Coordinate pos = mc.getPlayerPosition();
    // mc.setBlock(pos, mcpp::Blocks::GRASS);

    mc.drawLine(5);


    return 0;
}