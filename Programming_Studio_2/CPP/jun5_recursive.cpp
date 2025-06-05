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

void hello(int counter) {
    if (counter == 0) return;

    // int

    hello(counter-1);

    cout << counter << ". hello" << endl;
}

void count(int num) {

    // base case
    if (num == 0) return;

    // print first, recurse later
    cout << num << endl;

    count(num - 1);
}

void countFrom1(int num) {

    // base case
    if (num == 0) return;

    // swap these 2 lines
    // recurse first, print later
    countFrom1(num - 1);

    cout << num << endl;
}


// Repetition: iterations (for/while) vs recursion


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


    // hi(1)
    // 1 -> 10
    // 1. Hi
    // 2. Hi
    // ...
    // 10. Hi


    // 2.
    // recursive_factorial(int a)
    // int recursive_factorial(5) -> 120


    // // factorial !
    // // 5! = 5x4x3x2x1 = 120

    // cout << "5! = " << factorial(5) << endl;

    
    // hi(2);

    // hello(9);

    // count(5); // -> 5 -> pop6
        // count(4) -> 4 -> pop5
        //     count(3) -> 3 -> pop4
        //         count(2) -> 2 -> pop3
        //             count(1) -> 1 -> pop2
        //                 count(0) -> null -> pop1

    
    countFrom1(5); //  -> 5
    //     countFrom1(4); -> 4
    //         countFrom1(3); -> 3
    //             countFrom1(2); -> 2
    //                 countFrom1(1);  -> 1
    //                     countFrom1(0); -> null -> pop1



    // HW:
    // prime number

    is_prime(17) -> true
    is_prime_recursive(17) -> true
    

    return 0;
}
