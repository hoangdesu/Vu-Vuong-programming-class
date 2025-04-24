/*
In this exercise, you are required to implement the C++ function findMultiples which takes a 2D vector of integers and an integer as input. The goal is to identify all integers within the 2D vector that are multiples of the given integer. The function should return a vector containing all unique integers from the 2D vector that are multiples of the given number.The details of the function are given below. You are provided with the following files:

main.cpp - provided for you to use as you develop your code
Task.h - header file (read only)
Task.cpp - you will write your assessed C++ code in this file
utilities.h - (hidden) contains printVector for use as you develop your code
Function Details

Implement the following function:

std::vector<int> findMultiples(const std::vector<std::vector<int>>& numbers, int multiple);
The input parameters are:

numbers: a 2D vector of integers.
multiple: An integer that your code needs to check all integers in numbers against.
The function should return:

A vector of integers containing all the unique integers from numbers that are multiples of multiple.
The order of integers in the vector doesn't matter
Example

Given the following vector and function call:

std::vector<std::vector<int>> numbers = {
    {10, 20, 30}, 
    {15, 25, 35}, 
    {20, 40, 60}
};
std::vector<int> result = findMultiples(numbers, 5);
The result vector should contain (the order of the integers doesn't matter):

{10, 15, 20, 25, 30, 35, 40, 60}
NOTE

Note that 20 appears in two sub-vectors but should only be included once in the result.
HINT Use the modulo operator % to check if a number is a multiple of the given integer.
*/


#include <iostream>
#include <vector>
#include <string>
#include "Task.h"
// #include "utilities.h" // contains printVector for use as you develop your code

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

    std::vector<std::vector<int>> numbers = {{12, 20, 30}, {15, 25, 35}, {20, 40, 60}};
    int multiple = 5;
    std::vector<int> result = findMultiples(numbers, multiple);
     
    printVector(result);

   return EXIT_SUCCESS;
}

