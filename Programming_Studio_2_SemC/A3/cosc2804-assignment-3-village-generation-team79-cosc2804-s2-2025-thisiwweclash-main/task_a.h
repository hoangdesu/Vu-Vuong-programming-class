#ifndef TASK_A_H
#define TASK_A_H

#include <vector>
#include <mcpp/mcpp.h>
#include "plots.h"


std::vector<Plot> find_plots(mcpp::MinecraftConnection &mc, int village_size, int plot_border);

void terraform(mcpp::MinecraftConnection &mc, const std::vector<Plot> &plots, int plot_border);

void place_wall(mcpp::MinecraftConnection &mc, mcpp::Coordinate player, int village_size);

#endif 
