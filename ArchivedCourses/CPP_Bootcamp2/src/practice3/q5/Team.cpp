#include "Team.h"

using namespace std;

Team::Team(
    std::string name,
    std::string coach,
    int played)
{
    this->name = name;
    this->coach = coach;
    this->played = played;
}

string Team::formatInfo() {
    return "";
}