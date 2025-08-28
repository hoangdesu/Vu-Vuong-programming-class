#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <iomanip>
#include <sstream>

class Team
{
public:
    Team(std::string name = "No name", std::string coach = "No coach",  int played = 0);
    // virtual ~Team();
    std::string formatInfo();
    std::string name;
    std::string coach;
    int played;
};

#endif // TEAM_H