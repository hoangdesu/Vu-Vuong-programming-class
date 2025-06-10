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

class Maze {
    private:
        vector<vector<char>> maze;
        vector<vector<char>> floodedMaze;
    
    public:
        void build(vector<vector<char>>);
        vector<vector<char>>& getMaze();
        void print();

        bool validateIsolations();
        void fixIsolations();
};