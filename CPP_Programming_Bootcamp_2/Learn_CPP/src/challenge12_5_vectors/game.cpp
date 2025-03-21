#include "game.h"
#include <vector>

using namespace std;

vector<int>calculateTotalScores(vector<vector<int>> scores) {
    
    // scores[][] = 
    // {
    //     {10, 20, 30}, // i = 0
    //     {40, 50, 60}, // i = 1
    //     {70, 80, 90}  // i = 2
    // }

    // int results[] = new int[scores.size()];
    
    vector<int> res;

    for (int i = 0; i < scores.size(); i++) {
        int total = 0;
        for (int j = 0; j < scores[i].size(); j++) {
            total += scores.at(i).at(j);
        }
        res.push_back(total);
    }

    return res;
}