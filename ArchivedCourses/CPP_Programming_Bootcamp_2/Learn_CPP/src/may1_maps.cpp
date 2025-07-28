#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> countWords(const vector<vector<string>> &wordMatrix) {
    // TODO
}

int main() {

    map<string, string> capital_countries = {
        {"vietnam", "saigon"},
        {"japan", "tokyo"}
    };

    // modifying values
    capital_countries["vietnam"] = "hanoi";

    // adding new pairs
    capital_countries["korea"] = "seoul";
    capital_countries.insert({"england", "london"});

    // accessing values using keys
    cout << capital_countries.at("vietnam") << endl; // throw error when key not found at compiled time
    cout << capital_countries["korea"] << endl;

    // loop through all the pairs inside the map
    for (auto pair : capital_countries) {
        cout << "key = " << pair.first << " | value = " << pair.second << endl;
    }

    if (capital_countries.contains("france")) {
        cout << "France exists";
    } else {
        cout << "France does NOT exist";
    }

    // Constant Lookup time: 0(1)

    vector<vector<string>> wordMatrix = {
        {"apple", "banana", "apple"},
        {"orange", "banana", "grape"},
        {"grape", "apple", "melon"}
    };

    map<string, int> appearances = countWords(wordMatrix);

    output: 
    {
        "apple": 3,
        "banana": 2,
        "orange": 1,
        "grape": 2,
        "melon": 1
    }


    return EXIT_SUCCESS;
}
