#include <iostream>
// #include "Task.h"
// #include "utilities.h" // (hidden) contains printVector for testing
#include <vector>
#include <string>

using namespace std;

vector<string> extractUniqueWords(const vector<vector<string>> &wordMatrix)
{
    vector<string> res;

    for (vector<string> row : wordMatrix) {
        for (string word : row) {
            bool exists = false;
            for (string entry : res) {
                if (word == entry) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                res.push_back(word);
            }
        }
    }

    // for (int i = 0; i < wordMatrix.size(); i++) {
    //     for (int j = 0; j < wordMatrix[i].size(); j++) {
    //         string word = wordMatrix[i][j];
    //         // cout << word << endl;

    //         // using linear search to find if a word already exists in the vector
    //         bool exists = false;
    //         for (int k = 0; k < res.size(); k++) {
    //             if (res[k] == word) {
    //                 exists = true;
    //                 break;
    //             }
    //         }

    //         // if the word is not already in the result vector, add it to the vector
    //         if (!exists) {
    //             res.push_back(word);
    //         }
    //     }
    // }

    return res;
}

int main()
{
    vector<vector<string>> wordMatrix = {
        {"apple", "banana", "apple"},
        {"orange", "banana", "grape"},
        {"grape", "apple", "melon"}
    };

    vector<string> uniqueWords = extractUniqueWords(wordMatrix);

    // printVector(uniqueWords);
    cout << "{ ";
    for (string word : uniqueWords)
    {
        cout << word << ", ";
    }
    cout << " }\n";

    return EXIT_SUCCESS;
}
