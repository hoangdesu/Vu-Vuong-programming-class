#include <iostream>

#include "Team.h"
// #include "Team.cpp" // You can use this class (implementation is hidden)
#include "SoccerTeam.h"
#include "TeamList.h"
#include "utilities.h" // Includes escapeString(std::string) for use to develop/test (see zylab 20.2)
// #include "utilities.cpp" 

int main()
{
    //  /***********************************************************************
    //    * This code is provided as a starting point for development and testing
    //    * Please modify the code below as you develop your program.
    //    * **********************************************************************/

    SoccerTeam nufc("Newcastle United", "Eddie Howe", 32, 15, 12, 5);
    SoccerTeam spurs("Tottenham Hotspurs", "Ange Postecoglou", 32, 18, 8, 6);
    Team hawks("Hawthorn", "Sam Mitchell", 15);
    Team demons("Melbourne", "Simon Goodwin", 5);

    std::string test_str = nufc.formatInfo();
    std::cout << test_str << " " << test_str.length() << "\n\n";

    TeamList teamList;
    teamList.addTeam(&nufc);
    teamList.addTeam(&hawks);
    teamList.addTeam(&spurs);
    teamList.addTeam(&demons);


    // for (auto team : teamList.teams) {

    // }

    // std::cout << teamList.formatTeamList() << std::endl;
    // std::string team_list = teamList.formatTeamList();
    // std::cout << escapeString(team_list) << std::endl;

    return EXIT_SUCCESS;
}