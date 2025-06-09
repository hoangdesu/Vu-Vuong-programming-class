#include <iostream>
#include <vector>

#include "Maze.h"
// #include "MazeReadWriteUtils.h"

#include <mcpp/mcpp.h>

using namespace std;

void Maze::build(vector<vector<char>> maze)
{
    this->maze = maze;
}

vector<vector<char>> &Maze::getMaze()
{
    return this->maze;
}

void Maze::print()
{
    std::cout << "\n** Printing Maze Structure FROM MAZE CLASS **" << std::endl;
    for (unsigned int z = 0; z < this->maze.size(); z++)
    {
        for (unsigned int x = 0; x < this->maze[0].size(); x++)
        {
            if (this->maze[z][x] == 'x')
            {
                cout << 'x';
            }
            else
            {
                cout << '.';
            }
        }
        cout << endl;
    }
    cout << "**End Printing Maze**" << endl;
    cout << endl;
}

// HELPERS

void dfs(vector<vector<char>> &maze, int row, int col)
{

    // Base case: check boundary conditions and wrong char
    if (row < 0 || row >= maze.size() ||
        col < 0 || col >= maze[0].size() ||
        maze[row][col] != '.')
    {
        // Backtrack if pixel is out of bounds or char doesn't match
        cout << "reached based case in dfs" << endl;
        return;
    }

    // Update the char of the current pixel
    maze[row][col] = 'o';
    cout << "updating maze[row][col]: " << row << " - " << col << endl;

    // Recursively visit all 4 connected neighbors
    dfs(maze, row + 1, col);
    dfs(maze, row - 1, col);
    dfs(maze, row, col + 1);
    dfs(maze, row, col - 1);
}

void floodFill(vector<vector<char>> &maze, int row, int col)
{

    // changing . to o
    if (maze[row][col] == 'o')
    {
        cout << "changing to o: row = " << row << "col = " << col << endl;
        return;
    }

    // Call DFS to start filling
    cout << "calling dfs: " << row << " - " << col << endl;
    dfs(maze, row, col);
}

bool Maze::validateIsolations()
{
    vector<vector<char>> copy = this->maze;

    // TODO: check if char is a dot before calling floodfill
    floodFill(copy, 1, 3);

    for (vector<char> row : copy)
    {
        for (char c : row)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    for (vector<char> row : copy)
    {
        for (char c : row)
        {
            if (c == '.')
                return false;
        }
        cout << endl;
    }

    return true;

    // printMaze(copy);
}