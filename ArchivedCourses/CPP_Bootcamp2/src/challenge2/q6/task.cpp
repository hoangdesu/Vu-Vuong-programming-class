#include "task.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

std::vector<std::string> readLogFile(const std::string& filename) {
    std::vector<std::string> lines;

    ifstream inFS;
    inFS.open(filename);

    if (!inFS.is_open()) {
        cout << "Could not open file!" << std::endl;

        // return if error
        // return EXIT_FAILURE
        return {""};
    }

    if (inFS.good()) {
        string line;
        while (getline(inFS, line)) {
            lines.push_back(line);
        }
    }

    // if (lines.size() == 0)
    //     return 

    return lines;
}

// Method 1: build strings
vector<vector<string>> build_string(const vector<string>& logs) {
    vector<vector<string>> processedLogs;

    cout << "using method 1: build string" << endl;

    for (string line : logs) {
        vector<string> entries;
        string date_timestamp;
        string error_msg;

        
        int i = 0;
        while (line[i] != ' ') {
            date_timestamp += line[i];
            i++;
        }

        // skip the whitespace char
        i++;

        while (line[i] != '\0') {
            error_msg += line[i];
            i++;
        }

        // build the 1D vector -> ['timestamp', 'error']
        entries.push_back(date_timestamp);
        entries.push_back(error_msg);

        // push this 1D vector into the main 2D vector 
        // [
        //     ['ts1, er1'], 
        //     ['ts2', 'er2'], 
        //     ...,
        // ]

        processedLogs.push_back(entries);
    }

    return processedLogs;
}


// Method 2: using the input string stream C++ class
vector<vector<string>> build_tokens(const vector<string>& logs) {
    vector<vector<string>> processedLogs;

    cout << "using method 2: iss" << endl;

    for (string line : logs) {
        istringstream iss(line);

        string token;
        vector<string> entries;
        while (iss >> token) {
            entries.push_back(token);
        }

        processedLogs.push_back(entries);
    }

    return processedLogs;
}


std::vector<std::vector<std::string>> processLogEntries(const std::vector<std::string>& logs) {
    // vector<vector<string>> processedLogs = build_string(logs);

    vector<vector<string>> processedLogs = build_tokens(logs);

    return processedLogs;
}
