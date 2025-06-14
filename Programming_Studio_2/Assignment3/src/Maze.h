#include <iostream>
#include <vector>

#include <mcpp/mcpp.h>

using namespace std;

// class MazeUtils {
//     vector<vector<char>> maze;

//     void buildMaze(vector<vector<char>> maze);

//     void clearTerrain(vector<vector<char>> maze);
// }


// void buildMaze(vector<vector<char>> maze);


// void buildMaze(vector<vector<char>> maze) {
//     cout << "building maze...";
// }

struct Entrance {
    int i;
    int j;
};

class Maze {
    private:
        vector<vector<char>> maze;
        vector<vector<char>> floodedMaze;

        mcpp::MinecraftConnection& mc; 
        mcpp::Coordinate entrance;

        Entrance entranceIndices;

    
    public:
        // constructor
        Maze(mcpp::MinecraftConnection& mc) : mc(mc) {}

        void build(vector<vector<char>>);
        vector<vector<char>>& getMaze();
        void print();

        // validation methods
        bool validateIsolations();
        void fixIsolations();

        // 
        void draw();
};