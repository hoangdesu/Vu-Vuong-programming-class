#include "plots.h"

Plot::Plot(mcpp::Coordinate origin, mcpp::Coordinate bound, mcpp::Coordinate entrance)
    : origin(origin), bound(bound), entrance(entrance)
{
    center = {
        (origin.x + bound.x) / 2,
        (origin.y + bound.y) / 2,
        (origin.z + bound.z) / 2
    };
}
