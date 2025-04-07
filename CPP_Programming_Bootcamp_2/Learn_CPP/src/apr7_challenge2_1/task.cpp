#include "task.h"
#include <iostream>

int updateAndCalculateIncrease(int *num1, int &num2, int num3) {
//    int n1 = *num1;
//    int n2 = num2;
//    int n3 = num3;

    // Add num3 to the value of num1
    int n1 = *num1;
    *num1 += num3;
    int totalIncreaseN1 = *num1 - n1;

    // Multiply num2 by num3
    int n2 = num2;
    num2 = num2 * num3;
    int totalIncreaseN2 = num2 - n2;

    int total = totalIncreaseN1 + totalIncreaseN2;

   return total;
}

// int updateAndCalculateIncrease(int *num1, int &num2, int num3) {
//     int *a = &(*num1);
//     int b = num2;
//     &(*num1) = *a + &num3;
//     num2 = num2 * num3;
    
//     int increNum1 = &(*num1) - a;
//     int increNum2 = num2 - b;
//     int total = increNum1 + increNum2;

//     return total;
// }