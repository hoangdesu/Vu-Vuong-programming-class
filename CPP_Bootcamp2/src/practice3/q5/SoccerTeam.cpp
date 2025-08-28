#include "SoccerTeam.h"

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

SoccerTeam::SoccerTeam(
    std::string name,
    std::string coach,
    int played,
    int won,
    int lost,
    int drawn)
{
    this->name = name;
    this->coach = coach;
    this->played = played;
    this->won = won;
    this->lost = lost;
    this->drawn = drawn;
}

string SoccerTeam::formatInfo() {
    // TODO

    // Print column headers
    // cout << "| " << "name" << " ... " << "| " << "coach" << " ... " << "| " << "played" << " ... " << "| " << "won" << "..."

    ostringstream oss;

    // oss << string((19 - "name".length()), ' ');

    // oss << "| name" << setw(19 - string("name").length())
    //     << "| coach" << setw(19 - string("coach").length())
    //     << "| played" << setw(9 - string("played").length())
    //     << "| won" << setw(9 - string("won").length())
    //     << "| lost" << setw(9 - string("lost").length())
    //     << "| drawn" << setw(9 - string("drawn").length())
    //     << "|" << endl;

    oss << "| name" << string((19 - string("name").length()), ' ')
        << "| coach" << string((19 - string("coach").length()), ' ')
        << "| played" << string((9 - string("played").length()), ' ')
        << "| won" << string((9 - string("won").length()), ' ')
        << "| lost" << string((9 - string("lost").length()), ' ')
        << "| drawn" << string((9 - string("drawn").length()), ' ')
        << "|" << endl;

    oss << string(oss.str().length() - 1, '=') << endl;

    // Print team info
    oss << "| " << this->name << string((19 - string(this->name).length()), ' ')
        << "| " << this->coach << string((19 - string(this->coach).length()), ' ')
        << "| " << this->played << string(9 - to_string(this->played).length(), ' ')
        << "| " << this->won << string(9 - to_string(this->won).length(), ' ')
        << "| " << this->lost << string(9 - to_string(this->lost).length(), ' ')
        << "| " << this->drawn << string(9 - to_string(this->drawn).length(), ' ')
        << "|" << endl;

    // oss << this->name << "..." << this->coach;

    return oss.str();
}