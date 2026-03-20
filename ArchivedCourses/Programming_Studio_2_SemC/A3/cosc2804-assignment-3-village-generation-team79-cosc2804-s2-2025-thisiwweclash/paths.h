#ifndef PATHS_H
#define PATHS_H

#include <mcpp/mcpp.h>

class Path {
    public:
        mcpp::Coordinate start ;
        mcpp::Coordinate end ;
} ;

std::vector<mcpp::Coordinate> find_path(mcpp::MinecraftConnection &mc,
                                        const mcpp::Coordinate &start,
                                        const mcpp::Coordinate &goal,
                                        const std::vector<class Plot> &plots);


#endif