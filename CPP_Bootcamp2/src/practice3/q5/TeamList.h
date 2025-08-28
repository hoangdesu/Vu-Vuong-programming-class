#ifndef TEAMLIST_H
#define TEAMLIST_H

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "Team.h"
#include "SoccerTeam.h"


class TeamList {
private:
    std::vector<Team*> teams;

public:
    void addTeam(Team* team);
    // std::string formatTeamList();
};

#endif // TEAMLIST_H