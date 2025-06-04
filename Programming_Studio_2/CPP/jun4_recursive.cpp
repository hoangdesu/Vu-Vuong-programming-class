#include <iostream>

using namespace std;

// recursive function
void hi(int counter) {
    // base case
    if (counter == 10) {
        cout << "Reached base case in the recursive function 'hi()'" << endl;
        return;
    }

    cout << counter << ". Hi!" << endl;
    hi(counter+1);
}

int factorial(int a) {
    int f = a;

    while (a > 1) {
        a--;
        f *= a;
    }

    return f;
}

int main(void) {

    // hi(1);

    // int counter = 1;
    // while (1) {
    //     if (counter == 10) break;

    //     cout << counter++ << ". Hi!" << endl;
    // }

    // 1.
    // void count(from, to);
    // count(2, 10)
    // 2, 3, 4, 5 ... 10

    recursive_factorial(int a)
    int recursive_factorial(5) -> 120


    // factorial !
    // 5! = 5x4x3x2x1 = 120

    cout << "5! = " << factorial(5) << endl;

    
    return 0;
}
