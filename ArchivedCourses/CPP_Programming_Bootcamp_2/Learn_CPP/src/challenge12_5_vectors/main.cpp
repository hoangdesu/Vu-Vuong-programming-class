#include <iostream>
#include <vector>
#include "game.h"
// #include "utilities.cpp" // includes utility function: print_1D_vector

using namespace std;

void print_1D_vector(std::vector<int> scores) {
    cout << "{ ";
    for (int i = 0; i < scores.size(); i++) {
        cout << scores[i];
        if (i != scores.size() - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;
}

int main() {
    std::vector<std::vector<int>> scores = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    std::vector<int> totalScores = calculateTotalScores(scores);
    print_1D_vector(totalScores);
    return EXIT_SUCCESS;
}