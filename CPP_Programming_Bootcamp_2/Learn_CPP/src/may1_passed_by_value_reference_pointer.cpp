#include <iostream>

using namespace std;

// pass by value
// void doubleValue(int x) {
//     x = x * 2;
// }

// pass by reference
void doubleValue(int& x) {
    x = x * 2;
}

// pass by pointer
void doubleValuePointer(int* xPtr) {
    *xPtr *= 2;
}

// reassigning returned value
int doubleValueJava(int x) {
    return x * 2;
}

int main() {

    // Pass by value 
    // Pass by reference
    // Pass by pointer

    // int nums[] = {1, 2, 3};

    // using copied value
    // for (int num : nums) {
    //     num *= 2;
    // }

    // equivalent to this:
    // for (int i = 0; i < nums_len; i++) {
    //     int num = nums[i];
    //     num *= 2;
    // }

    // direct access using index
    // sizeof: runtime operator
    // compiled time vs run time
    // int nums_len = sizeof(nums) / sizeof(nums[0]);
    // for (int i = 0; i < nums_len; i++) {
    //     nums[i] *= 2;
    // }

    // pass by reference
    // for (int& num : nums) {
    //     num *= 2;
    // }

    // for (int num : nums) {
    //     cout << num << " ";
    // }

    // 1, 2, 3
    // 2, 4, 6

    int x = 1;

    // doubleValue(x);
    // doubleValuePointer(&x);
    x = doubleValueJava(x);

    cout << "x outside: " << x << endl; // 1 or 2?
    cout << &x << endl ;

    return EXIT_SUCCESS;
}
