#ifndef TASK_H
#define TASK_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>


std::vector<std::string> readLogFile(const std::string& filename);
std::vector<std::vector<std::string>> processLogEntries(const std::vector<std::string>& logs);


#endif  