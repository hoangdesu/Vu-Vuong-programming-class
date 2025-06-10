#include <iostream>
#include <exception>
#include <memory>

#include <mcpp/mcpp.h>

#include "menuUtils.h"
#include "MazeReadWriteUtils.h"
#include "Maze.h"

#define NORMAL_MODE 0
#define TESTING_MODE 1

enum States
{
    ST_Main,
    ST_GetMaze,
    ST_SolveMaze,
    ST_Creators,
    ST_Exit
};

int main(int argc, char **argv)
{

    bool mode = NORMAL_MODE;
    States curState = ST_Main;

    // MazeUtil mazeUtils;
    // mazeUtils.maze

    // read and parse program arguments
    try
    {
        // Read the mode
        if (argc > 1)
        {
            if (argc > 2)
            {
                throw std::invalid_argument("Can only read one command line argument, you entered more");
            }
            std::string input(argv[1]);
            if (input == "-testmode")
            {
                mode = TESTING_MODE;
                cout << ">> Running in TESTING MODE" << endl;
            }
            else
            {
                throw std::invalid_argument("Enter argument `-testmode` if you need to operate in testing mode");
            }
        }
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "Invalid argument: " << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    printStartText();

    // std::shared_ptr<Maze> maze = nullptr;

    // TODO: create a shared instance of mc
    // mcpp::MinecraftConnection mc;

    // if (mc == nullptr)
    // {
    //     std::cerr << "Error: server is not running." << endl;
    //     return 1;
    // }

    // export mc to global scope

    // create a global shared object
    Maze maze;

    // State machine for menu
    while (curState != ST_Exit)
    {

        if (curState == ST_Main)
        {
            // In main menu
            printMainMenu();

            int menuItem = 0;

            std::cin >> menuItem;
            if (menuItem == 1)
            {
                curState = ST_GetMaze;
            }
            else if (menuItem == 2)
            {

                // // TODO: Build maze
                // std::cout << "TODO: Not implemented yet." << std::endl;
                std::cout << mode << std::endl; // remove this during implementation
                                                //  added to make sure the starter code compiles with
                                                //  all flags

                // // testing...
                // std::vector<std::vector<char>> mazeStructure;
                // mcpp::Coordinate basePoint(0, 0, 0);
                // bool success = readMaze(mazeStructure, basePoint);
                // if (success)
                // {
                //     std::cout << "Maze read successfully" << std::endl;
                //     curState = ST_Main;
                //     // printMaze(mazeStructure);
                //     // maze.buildMaze(mazeStructure);
                // }
                // else
                // {
                //     std::cout << "Error Reading Maze. Try again." << std::endl;
                // }
            }
            else if (menuItem == 3)
            {
                curState = ST_SolveMaze;
            }
            else if (menuItem == 4)
            {
                curState = ST_Creators;
            }
            else if (menuItem == 5)
            {
                curState = ST_Exit;
            }
            else
            {
                std::cout << "Input Error: Enter a number between 1 and 5 ...." << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        }
        else if (curState == ST_GetMaze)
        {
            // In getMaze menu
            printGenerateMazeMenu();

            int menuItem = 0;

            std::cin >> menuItem;
            if (menuItem == 1)
            {
                // Reading Maze from terminal
                // TODO: Read the maze to an appropriate ADT
                //          and use it throughout the code
                std::vector<std::vector<char>> mazeStructure;
                mcpp::Coordinate basePoint(0, 0, 0);
                bool success = readMaze(mazeStructure, basePoint);

                if (success)
                {
                    std::cout << "Maze read successfully" << std::endl;
                    curState = ST_Main;
                    printMaze(mazeStructure);

                    maze.build(mazeStructure);
                    bool isolatedOK = maze.validateIsolations();
                    // bool loopsOK = maze.validateLoops();

                    cout << "isolatedOK: " << isolatedOK << endl;

                    // if not ok: maze.fixIsolations()
                    if (!isolatedOK)
                    {
                        maze.fixIsolations();
                        // isolatedOK = maze.validateIsolations();
                        cout << "\nAFTER FIX: isolatedOK: " << isolatedOK << endl;

                        for (vector<char> row : maze.getMaze())
                        {
                            for (char c : row)
                            {
                                cout << c << " ";
                            }
                            cout << endl;
                        }
                    }

                    // if (!isolatedOK && !loopsOK)
                    // {
                    //     cout << "Errors detected. Would you like to automatically fix them? (y/n)";
                    //     // ...
                    // }
                    // 1. fix isolation
                    // maze.fixIsolations();

                    // // 2. fix loops
                    // maze.fixLoops();

                    // // 3. fix entrances
                    // maze.fix();
                }
                else
                {
                    std::cout << "Error Reading Maze. Try again." << std::endl;
                }
            }
            else if (menuItem == 2)
            {
                // TODO: Generating random maze
                //  std::cout << "TODO: Not implemented yet." << std::endl;
                //  buildMaze(mazestr)
            }
            else if (menuItem == 3)
            {
                curState = ST_Main;
            }
            else
            {
                std::cout << "Input Error: Enter a number between 1 and 3 ...." << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        }
        else if (curState == ST_SolveMaze)
        {
            printSolveMazeMenu();

            int menuItem = 0;

            std::cin >> menuItem;
            if (menuItem == 1)
            {
                // Solve Manually
                std::cout << "TODO: Not implemented yet." << std::endl;
                // printMaze(maze.getMaze());
                maze.print(); //  test
            }
            else if (menuItem == 2)
            {
                // Show Escape Route
                std::cout << "TODO: Not implemented yet." << std::endl;
            }
            else if (menuItem == 3)
            {
                curState = ST_Main;
            }
            else
            {
                std::cout << "Error: input a valid number between 1 and 3...." << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        }
        else if (curState == ST_Creators)
        {
            printTeamInfo();
            curState = ST_Main;
        }
    }

    printExitMassage();

    return EXIT_SUCCESS;
}