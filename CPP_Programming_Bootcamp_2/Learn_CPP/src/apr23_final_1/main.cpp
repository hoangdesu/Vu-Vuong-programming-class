/*
In this exercise you are required to implement the C++ function getMultiplesInRange that returns a vector of all multiples of a given integer within a specified range. The details for the function are provided below

You are provided with the following files:

main.cpp - provided for you to use as you develop your code
Task.h - header file (read only)
Task.cpp - you will write your assessed C++ code in this file
utilities.h - (hidden) contains printVector for use as you develop your code
Function Details

Implement the following function:

std::vector<int> getMultiplesInRange(int num, int lower_bound, int upper_bound);
The function has the following input parameters are

num: An integer, for which multiples need to be found.
lower_bound: The starting point of the range (inclusive).
upper_bound: The end point of the range (inclusive).

The function should return:

A vector of integers containing all multiples of num within the range [lower_bound, upper_bound].
NOTE the integers should be in ascending order (as shown in the example below)
If no multiples are found or the inputs are invalid (e.g., lower_bound > upper_bound or num <= 0), return an empty vector.
Example

For the following function call:

std::vector<int> result = getMultiplesInRange(5, 10, 50);
The result vector should contain the following values:

{10, 15, 20, 25, 30, 35, 40, 45, 50}
*/

#include <iostream>
#include <vector>
#include <string>
#include "Task.h"
// #include "utilities.h"

using namespace std;

void printVector(vector<int> vec) {
    for (int n : vec) {
        cout << n << ", ";
    }
    cout << endl;
}

int main()
{

   /***********************************************************************
    * This code is provided as a starting point for development and testing
    * Please modify the code below as you develop your program.
    **********************************************************************/

    int num = 5;
    int lower_bound = 10;
    int upper_bound = 50;
    std::vector<int> result = getMultiplesInRange(num, lower_bound, upper_bound); 
    printVector(result);

   return EXIT_SUCCESS;
}

