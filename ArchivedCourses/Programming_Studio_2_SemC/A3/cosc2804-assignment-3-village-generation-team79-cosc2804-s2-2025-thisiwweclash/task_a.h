#ifndef TASK_A_H
#define TASK_A_H

#include <vector>
#include <mcpp/mcpp.h>
#include "plots.h"

std::vector<Plot> find_plots(mcpp::MinecraftConnection &mc,
                             const mcpp::Coordinate &village_center,
                             int village_size,
                             int plot_border);

void terraform(mcpp::MinecraftConnection &mc,
               const std::vector<Plot> &plots,
               int plot_border,
               const mcpp::Coordinate &village_center,
               int village_size);

void place_wall(mcpp::MinecraftConnection &mc,
                const mcpp::Coordinate &village_center,
                int village_size);

std::vector<mcpp::Coordinate> generate_waypoints(
    const std::vector<Plot> &plots,
    const mcpp::Coordinate &village_center,
    int village_size);

#endif
