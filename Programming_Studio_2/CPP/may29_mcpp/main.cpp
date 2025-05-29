#include <iostream>
#include <string>

#include "mcpp/mcpp.h"

using namespace std;

int main(void) {

    cout << "hello from main" << endl;
    string name = "Vuong";

    mcpp::MinecraftConnection *mc = new mcpp::MinecraftConnection();

    mc->doCommand("time set day");
    mc->postToChat("hoho");

    return 0;
}