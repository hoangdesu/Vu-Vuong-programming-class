#include <mcpp/mcpp.h>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "plots.h"
#include "utils.h"
#include "task_a.h"
#include "task_b.h"
#include "task_c.h"

int main(const int argc, const char *const *const argv) {
    print_student_details();

    mcpp::MinecraftConnection mc;

    int village_size = 100;
    int plot_border = 5;
    int seed = static_cast<int>(std::time(nullptr));
    bool testmode = false;

    // Parsing command line arguments
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        size_t pos = arg.find('=');
        std::string key = arg.substr(0, pos);
        std::string value = (pos != std::string::npos) ? arg.substr(pos + 1) : "";

        if (key == "--village-size") village_size = stoi(value);
        else if (key == "--plot-border") plot_border = stoi(value);
        else if (key == "--seed") seed = stoi(value);
        else if (key == "--testmode") testmode = true;
        else {
            std::cerr << "Invalid argument " << key << std::endl;
            return EXIT_FAILURE;
        }
    }

    std::cout << "There are " << argc << " command line arguments.\n";
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << std::endl;

    print_command_line_arguments(0, 0, village_size, plot_border, seed, testmode);

    // Task A
    std::cout << "Task A: Finding Plots and Terraforming\n";

    mcpp::Coordinate player = mc.getPlayerPosition();
    int loc_x = player.x;
    int loc_z = player.z;
    int loc_y = mc.getHeight({loc_x, loc_z});

    mcpp::Coordinate village_center{loc_x, loc_y, loc_z};
    std::cout << "\tPlayer position: (" << loc_x << ", " << loc_y << ", " << loc_z << ")\n";

    std::cout << "\tBuilding walls...\n";
    place_wall(mc, village_center, village_size);

    std::cout << "\tFinding plots...\n";
    auto plots = find_plots(mc, village_center, village_size, plot_border);

    std::cout << "\tTerraforming plots...\n";
    terraform(mc, plots, plot_border, village_center, village_size);

    auto waypoints = generate_waypoints(plots, village_center, village_size);
    for (auto &w : waypoints)
        mc.setBlock(w, mcpp::Blocks::GLOWSTONE);

    // Task B
    std::cout << "Task B: Building Houses\n";
    build_buildings(mc, plots, testmode);

    // Task C
    std::cout << "Task C: Paths\n";
    connect_waypoints(mc, plots, waypoints);
    connect_buildings(mc, plots, waypoints);

    return 0;
}
