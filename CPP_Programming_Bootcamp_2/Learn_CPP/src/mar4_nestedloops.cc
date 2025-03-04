#include <iostream>
#include <string>

using namespace std;

// Prototypes
void printPyramid(int height);

int main(void) {
    
    cout << "Enter pyramid height: ";
    int height;
    cin >> height;

    // Enter pyramid height: 4

//       #  #
//      ##  ##
//     ###  ###
//    ####  ####

// height = 4:

// #
// ##
// ###
// ####



//       #
//      ##
//     ###
//    ####


// Lines   Spaces  #
// 1       3       1
// 2       2       2
// 3       1       3
// 4       0       4


    printPyramid(height);

    return 0;
}

// Function implementations
void printPyramid(int height) {
    
    // int lines, spaces, hashTags??
    for (int line = 1; line <= height; line ++) {
        for (int space = height - line; space >= 1; space--) {
            cout << " ";
        }

        for (int hash = 1; hash <= line; hash++) {
            cout << "#";
        }

        cout << "  ";

        for (int hash = 1; hash <= line; hash++) {
            cout << "#";
        }

        cout << endl;
    }
}