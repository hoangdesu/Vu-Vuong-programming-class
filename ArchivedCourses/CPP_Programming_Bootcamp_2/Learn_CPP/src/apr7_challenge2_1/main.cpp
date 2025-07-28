// In this exercise you are asked to implement a C++ function as detailed below. You are provided with the following files:

// main.cpp - Sample code provided to help you develop your code. This is not used to test your code.
// task.h - Header file (this is read-only).
// task.cpp - You will write your assessed C++ code in this file.
// Task

// Implement the following function:

// int updateAndCalculateIncrease(int *num1, int &num2, int num3);
// The function takes the following parameters:

// num1, a pointer to an integer
// num2, a reference to an integer
// num3, an integer passed by value
// The function should:

// Add num3 to the value of num1
// Multiply num2 by num3
// Calculate the the total increase of num1 and num2 and return the result
// Example

// For the following:

// int num1 = 10;
// int num2 = 6;
// int num3 = 4;
// int result = updateAndCalculateIncrease(&num1, num2, num3);
// std::cout << "num1: " << num1 << " num2: " << num2 << " increase: " << result << std::endl;
// should output:

// num1: 14 num2: 24 increase: 22



// ```

#include "task.h"
#include <iostream>

int main()
{
   //  /***********************************************************************
   //  * This code is provided as a starting point for development and testing
   //  * Please modify the code below as you develop your program.
   //  * **********************************************************************/
    int num1 = 10;
    int num2 = 6;
    int num3 = 4;

    int result = updateAndCalculateIncrease(&num1, num2, num3);

    std::cout << "num1: " << num1 << " num2: " << num2 << " increase: " << result << std::endl;

    return EXIT_SUCCESS;
}


