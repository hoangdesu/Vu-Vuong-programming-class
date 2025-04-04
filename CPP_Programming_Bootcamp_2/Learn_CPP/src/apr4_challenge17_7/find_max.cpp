#include <iostream>
// #include "task.h"

// int find_max(int[] nums, int size) {

// }

using namespace std;

int main()
{
    int nums[] = {3, 1, 2, 9 ,5 , 4};
    
    int max = nums[0]; // assuming first number is the largest
    int len = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < len; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }

    // for (animal : animals) {
    //     if animal.age > max_age:
    //         max_age = animal.age
    // }

    cout << "Max num = " << max << endl;
    
    return 0;
}