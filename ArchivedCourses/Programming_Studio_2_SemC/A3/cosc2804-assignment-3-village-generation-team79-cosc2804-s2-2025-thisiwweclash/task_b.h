#ifndef TASK_B_H
#define TASK_B_H

#include <vector>
#include <mcpp/mcpp.h>
#include "plots.h"


void build_buildings(mcpp::MinecraftConnection &mc, const std::vector<Plot> &plots, bool testmode);


void build_house(mcpp::Coordinate origin, int width, int depth);

#endif // TASK_B_H