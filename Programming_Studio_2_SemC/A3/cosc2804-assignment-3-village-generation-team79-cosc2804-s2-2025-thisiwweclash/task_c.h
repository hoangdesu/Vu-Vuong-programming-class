#ifndef TASK_C
#define TASK_C

#include <vector>
#include <iostream>
#include "plots.h"
#include "paths.h"
#include <mcpp/mcpp.h>


void connect_waypoints(mcpp::MinecraftConnection& mc, const std::vector<Plot>& plots, const std::vector<mcpp::Coordinate>& waypoints);

void connect_buildings(mcpp::MinecraftConnection& mc, const std::vector<Plot>& plots, const std::vector<mcpp::Coordinate>& waypoints);

#endif