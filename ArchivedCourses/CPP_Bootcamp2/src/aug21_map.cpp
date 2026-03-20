#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, int> char_frequency(string text) {
    unordered_map<char, int> freq;

    for (char c : text) {
        if (!freq[c]) {
            freq[c] = 1;
        } else {
            freq[c] += 1;
        }
    }

    return freq;
}

int main() {

    unordered_map<string, string> countries;

    // key-value pairs
    countries["saigon"] = "vietnam";
    countries["tokyo"] = "korea";
    countries["tokyo"] = "japan";

    cout << countries["tokyo"] << endl;
    cout << countries["seoul"] << endl; // null
    cout << countries.at("saigon") << endl;

    // Iterate:

    for (auto i = countries.begin(); i != countries.end(); i++) {
        string key = i->first;
        string value = i->second;

        cout << "key = " << key << " - value = " << value << endl;
    }

    for (auto it : countries) {
        cout << "key: " << it.first << "value: " << it.second << endl;
    }

    // Big O notation
    // Lookup time: constant O(1)

    unordered_map<char, int> char_freq = char_frequency("abccd");

    for (auto it : char_freq) {
        cout << it.first << ": " << it.second << endl;
    }

    // => {
    //     'a': 1,
    //     'b': 1,
    //     'c': 2,
    //     'd': 1
    // }


    nums = [2,7,11,15], target = 17

    needs = {15, 10, 6}

    i=0 -> 3 => 
    2 -> 2 => 15
    7 -> 2,7 => 10
    11 -> {2,7,11} => 6
    15 ->

    compensate



    
    nums = [2,7,11,15], target = 26

    2 nested for loops: O(n^2)

    map: O(n) -> linear -> 1 for loop

    return EXIT_SUCCESS;
}