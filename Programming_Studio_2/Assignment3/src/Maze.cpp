#pragma once
#include <iostream>
#include <vector>

#include "Maze.h"

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

void dfs(vector<vector<char>> &maze, size_t row, size_t col)
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

    // check if char is a dot AND NOT ISOLATED before calling floodfill
    for (unsigned int i = 0; i < copy.size(); i++) {
        for (unsigned int j = 0; j < copy[i].size(); j++) {
            if (copy[i][j] == '.') {
                floodFill(copy, j, j);
                break;
            }
        }
    }

    // while c != '.':
    //     random i j

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

void Maze::fixIsolations()
{
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

    for (size_t i = 1; i < this->floodedMaze.size() - 1; i++)
    {
        for (size_t j = 1; j < this->floodedMaze[i].size() - 1; j++)
        {
            if (this->floodedMaze[i][j] == '.')
            {
                // TODO: check if i and j are in bound
                // ...
                // NOTE: currently not correct yet
                // if (i-2 < 0 || i+2 >= this->floodedMaze.size() - 1 || j-2 < 0 || j+2 >= this->floodedMaze[i].size() - 1)
                // {
                //     continue;
                // }

                // int x = -1, y = -1;

                // check if TOP wall is breakable
                if (i - 2 >= 0 && this->floodedMaze[i - 2][j] == 'O')
                {
                    // replacing the wall from ACTUAL MAZE from 'x' to '.'
                    this->maze[i - 1][j] = '.';
                    // x = i-1;
                    // y = j;
                    break;
                }

                // check if BOTTOM wall is breakable
                else if (i + 2 < this->floodedMaze.size() && this->floodedMaze[i + 2][j] == 'O')
                {
                    // replacing the wall from ACTUAL MAZE from 'x' to '.'
                    this->maze[i + 1][j] = '.';
                    // x = i+1;
                    // y = j;
                    break;
                }

                // check if RIGHT wall is breakable
                else if (j + 2 < floodedMaze[i].size() && this->floodedMaze[i][j + 2] == 'O')
                {
                    // replacing the wall from ACTUAL MAZE from 'x' to '.'
                    this->maze[i][j + 1] = '.';
                    break;
                }

                // check if LEFT wall is breakable
                else if (j - 2 >= 0 && this->floodedMaze[i][j - 2] == 'O')
                {
                    // replacing the wall from ACTUAL MAZE from 'x' to '.'
                    this->maze[i][j - 1] = '.';
                    break;
                }
            }
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

void Maze::draw()
{
    mcpp::Coordinate pos = this->mc.getPlayerPosition();
    cout << pos;

    // i: 0 
    // j: 0 -> size[i]-1

    // i: 0 -> size-1

    cout << "Coordinates of the entrance: ";

    // int i = 0, j = 0;

    // while (true) {
    //     if (this->maze[i][j] == '.') {
    //         break;
    //     }
        
    //     if (j < maze[i].size() - 1) {
    //         j++;
    //     }

    //     this->entranceIndices.i = i;
    //     this->entranceIndices.j = j;
    // }

    // check entrance's position, draw entrance relatively from the origin
}
