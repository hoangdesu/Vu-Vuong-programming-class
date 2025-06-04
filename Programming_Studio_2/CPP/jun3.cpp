#include <iostream>

using namespace std;

int main(void) {
    // Enter the length and width of maze:
    // 35
    // Enter the maze structure:
    // xxx
    // ..x
    // x.x
    // x.x
    // xxx
    
    // -> char maze[5][3]

    cout << "Enter the length and width of maze: " << endl; 
    int length, width;
    cin >> length >> width; // e.g 3 5

    // TODO: should handle error

    char maze[width][length]; // -> 5x3

    cout << "Enter the maze structure: " << endl;

    // Get terminal input
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            char c;
            cin >> c;

            if (c != 'x' && c != '.') {
                cerr << "Invalid character(s). Only accept 'x' or '.'" << endl;
                return 1;
            }

            maze[i][j] = c;
        }
    }


    cout << endl << "Maze:" << endl;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }


}
