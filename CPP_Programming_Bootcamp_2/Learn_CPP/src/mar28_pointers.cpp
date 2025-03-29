#include <iostream>
#include <vector>
#include <string>

using namespace std;

int fibonacci(int n) {
    // edge cases
    if (n < 1) return -1; // error code
    if (n == 1) return 0;
    if (n == 2) return 1;

    int a = 0;
    int b = 1;
    int temp = 0;
    for (int i = 0; i < n-2; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }

    return temp;
}

void hello(int i) {
    cout << "Hello " << i << endl;
    hello(i+1); // recursion
}


int main(void) {

    // cout << fibonacci(8) << endl;
    // cout << fibonacci(0) << endl;
    // cout << fibonacci(2) << endl;


    // function calling itself: recursion
    // hello(1);

    // int i = 0;
    // while (true) {
    //     cout << "Hello " << i++ << endl;
    // }


    // - functions are created on stack
    // - by default, vars inside a func are also created on stack
    // - if using "new" keyword, var is created on the heap memory


    return 0;
}
