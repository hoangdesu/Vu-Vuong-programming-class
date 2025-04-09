// 3-1-1990
// 4-2-1995
// 7-15-2020
// 12-13-2003

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// input: "March 1, 1990"
// output: "3-1-1990"
string parseDate(string date);
string GetMonthAsInt(string month) {

    int monthInt = 0;
    
    if (month == "January")
        monthInt = 1;
    else if (month == "February")
        monthInt = 2;
    else if (month == "March")
        monthInt = 3;
    else if (month == "April")
        monthInt = 4;
    else if (month == "May")
        monthInt = 5;
    else if (month == "June")
        monthInt = 6;
    else if (month == "July")
        monthInt = 7;
    else if (month == "August")
        monthInt = 8;
    else if (month == "September")
        monthInt = 9;
    else if (month == "October")
        monthInt = 10;
    else if (month == "November")
        monthInt = 11;
    else if (month == "December")
        monthInt = 12;


    return std::to_string(monthInt);
}

std::vector<std::string> splitString(const std::string& str, char delimiter = ' ') {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }

    return tokens;
}

vector<string> split(char *phrase, string delimiter){
    vector<string> list;
    string s = string(phrase);
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        list.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    list.push_back(s);
    return list;
}

int main() {
    vector<string> fileLines;

    ifstream file;
    file.open("./data/dates.txt"); // relative path
    // "/Users/brian/CLOUD/Teaching/Vu Vuong - Programming/CPP_Programming_Bootcamp_2/Learn_CPP/src/apr9_readingFile/data/dates.txt" // absolute path
    // C:\\...\...\.

    // good practice: check if the file has been opened successfully
    if (!file.is_open()) {
        cout << "Error openning file." << endl;
        return EXIT_FAILURE;
    }

    // getline(file, )
    // char c;
    // while (file.get(c)) {
    //     if (c == '\n') {
    //         cout << " - new line";
    //         continue;
    //     }
    //     cout << c;
        
    // }

    // get every line from the file, put them into the vector
    string line;
    while (getline(file, line)) {
        if (line != "-1") {
            fileLines.push_back(line);
        }
    }

    file.close();

    // display the raw data we read from the file
    cout << endl << "Raw data:" << endl;
    for (auto l : fileLines) {
        cout << l << endl;
    }

    
    // parse each date in the vector
    cout << endl << "Parsing data..." << endl;
    for (int i = 0; i < fileLines.size(); i++) {
        // string currentLine = fileLines[i];
        string parsedDate = parseDate(fileLines.at(i));
        cout << "new date: " << parsedDate << endl;
        fileLines[i] = parsedDate;
        // currentLine = parsedDate;
    }


    // range-based for loop (C++11)
    // display the vector with parsed data
    cout << endl << "Parsed data:" << endl;
    for (auto l : fileLines) {
        cout << l << endl;
    }


    ofstream writeFile;
    writeFile.open("./data/parsed-dates.dat");
    for (int i = 0; i < fileLines.size(); i++) {
        writeFile << fileLines[i];
        if (i < fileLines.size() - 1) writeFile << endl;
    }
    cout << "Successfully output to file parsed-dates.txt" << endl;

    writeFile.close();


    return EXIT_SUCCESS;
}

string parseDate(string date) {
    string month, day, year, res;

    // int endIndex = 0;
    // // while (date.at(endIndex) != ' ') {
    // //     endIndex++;
    // // }
    // cout << "endIndex = " << endIndex << endl;
    // month = date.substr(0, date.find(" "));
    // cout << "month = " << month << endl;

    // res += GetMonthAsInt(month);
    // res += "-"; 

    // int startIndex = endIndex + 2;
    // // endIndex;
    // // while (date.at(endIndex) != ' ') {
    // //     endIndex++;
    // // }
    // day = date.substr(date.find(" "), date.find(" ")+1);
    // cout << "date: " << date << endl;
    // cout << "day = " << day << endl;
    // res += day;
    // res += "-";

    vector<string> parts = splitString(date);
    month = GetMonthAsInt(parts[0]);
    day = parts[1];
    year = parts[2];

    res = month + "-" + day + "-" + year;


    // startIndex = endIndex + 1;
    // cout << "startIndex = " << startIndex << endl;
    // year = date.substr(startIndex);
    // cout << "year = " << year << endl;
    // res += year;

    
    // cout << "res = " << res << endl;
    // vector<string> splittedDates = split(date, " ");
    // for (auto s : splittedDates) {
    //     cout << s << endl;
    // }

    return res;
}

// s   e
//       s
//       e
//         s  e
// March 1 1990
