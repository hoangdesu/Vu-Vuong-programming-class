#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

const int ALLOCATED_LENGTH = 20; 
 
bool isSorted(const int *arr, const int logical_length, std::string order);
void prefixSumArray(const int *arr, int *prefix_sum, int logical_length);

#endif // TASK_H
