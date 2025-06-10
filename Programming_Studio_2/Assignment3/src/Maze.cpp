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
        // cout << "reached based case in dfs" << endl;
        return;
    }

    // Update the char of the current pixel
    maze[row][col] = 'O';
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
    if (maze[row][col] == 'O')
    {
        cout << "changing to O: row = " << row << "col = " << col << endl;
        return;
    }

    // Call DFS to start filling
    cout << "calling dfs: " << row << " - " << col << endl;
    dfs(maze, row, col);
}

bool Maze::validateIsolations()
{
    vector<vector<char>> copy = this->maze;

    // TODO: check if char is a dot AND NOT ISOLATED before calling floodfill
    // if ()
    floodFill(copy, 1, 4);

    this->floodedMaze = copy;

    cout << "\n>> FLOODED MAZE: " << endl;
    for (vector<char> row : floodedMaze)
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

void Maze::fixIsolations() {
    cout << "> before fixing isolations..." << endl;  

    for (vector<char> row : this->floodedMaze)
    {
        for (char c : row)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    // fixing...

    for (int i = 1; i < this->floodedMaze.size() - 1; i++)
    {
        bool cont = true;
        for (int j = 1; j < this->floodedMaze[i].size() - 1; j++)
        {
            if (this->floodedMaze[i][j] == '.')
            {
                // TODO: check if i and j are in bound
                // ...
                // NOTE: current not correct yet
                if (i-1 < 0 || i+1 >= this->floodedMaze.size() - 1 || j-1 < 0 || j+2 >= this->floodedMaze[i].size() - 1)
                {
                    continue;
                }

                // int x = -1, y = -1;

                // check if TOP wall is breakable
                if (this->floodedMaze[i-2][j] == 'O')
                {
                    // replacing the wall from ACTUAL MAZE from 'x' to '.'
                    this->maze[i-1][j] = '.';
                    // x = i-1;
                    // y = j;
                }

                // check if BOTTOM wall is breakable
                else if (this->floodedMaze[i+2][j] == 'O')
                {
                    // replacing the wall from ACTUAL MAZE from 'x' to '.'
                    this->maze[i+1][j] = '.';
                    // x = i+1;
                    // y = j;
                }

                // check if RIGHT wall is breakable
                else if (this->floodedMaze[i][j+2] == 'O')
                {
                    // replacing the wall from ACTUAL MAZE from 'x' to '.'
                    this->maze[i][j+1] = '.';
                    // x = i;
                    // y = j+1;
                }

                // check if LEFT wall is breakable
                else if (this->floodedMaze[i][j-2] == 'O')
                {
                    // replacing the wall from ACTUAL MAZE from 'x' to '.'
                    this->maze[i][j-1] = '.';
                    // x = i;
                    // x = i-1;
                }


                // TODO: check if the maze STILL needs to be fixed
                // validate maze -> flood fill again
                // floodFill(this->maze, x, y);

                if (this->validateIsolations())
                {
                    cont = false;
                    break;
                }
            }

            if (!cont) break;

        }
    }

    cout << "> after fixing isolations..." << endl;  

    for (vector<char> row : this->maze)
    {
        for (char c : row)
        {
            cout << c << " ";
        }
        cout << endl;
    }

}