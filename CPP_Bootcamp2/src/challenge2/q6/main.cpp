#include "task.h"
// #include "utilities.cpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() { 
   
   std::string filename = "log.txt";  
   std::vector<std::string> logs = readLogFile(filename);

   if (logs[0] == "") {
    return EXIT_FAILURE;
   }

   for (auto line : logs) {
    cout << line << endl;
   }

   std::vector<std::vector<std::string>> parsedLogs = processLogEntries(logs);
//    std::cout << print2DVec(parsedLogs);

    for (vector<string> line : parsedLogs) {
        for (string entry : line) {
            cout << entry << "...";
        }
        cout << endl;
    }


   return EXIT_SUCCESS;
}