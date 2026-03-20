#ifndef SOCCERTEAM_H
#define SOCCERTEAM_H

#include <vector>
#include <iomanip>
#include <sstream>
#include "Team.h"

class SoccerTeam : public Team
{

public:
    SoccerTeam(std::string name = "No name", std::string coach = "No coach",
               int played = 0, int won = 0, int lost = 0, int drawn = 0);
    std::string formatInfo();
    int won;
    int lost;
    int drawn;
};

#endif // SOCCERTEAM_H