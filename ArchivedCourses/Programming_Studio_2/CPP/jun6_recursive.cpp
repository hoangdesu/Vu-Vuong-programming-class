#include <iostream>

using namespace std;

void count(int from, int to) {
    if (from > to) return;
    cout << from << " ";
    count(from+1, to);
}

// bool is_prime(int num) {
//     if (num == 1) {
//         return true
//     } else if (num % 2 )
// }

// bool is_prime(int n) {
//     static int i = 2;

//     cout << "current i = " << i << endl;

//     if (n <= 2) return (n == 2);
//     if (n % i == 0) return false;
//     if (i * i > n) return true;

//     ++i;
//     bool result = is_prime(n);
//     if (i == 2) i = 2; // reset i after outermost call
//     return result;
// }

bool is_prime(int n, int i = 2)
{
    cout << "current i = " << i << endl;

    // Base cases
    if (n <= 2)
        return (n == 2) ? true : false;
    if (n % i == 0)
        return false;
    // if (i * i > n) // i > sqrt(n)
    if (i == n-1) // slower
        return true;

    // Check for next divisor
    return is_prime(n, i + 1);
}


int main(void) {

    
    // count(2, 9);


    // HW:
    // prime number

    // is_prime(17) -> true
    // is_prime_recursive(17) -> true

    cout << is_prime(17) << endl;
    cout << is_prime(18) << endl;

    // Notes: 2 ways to have 1 param but still can keep track of counter
    // 1. static var
    // 2. default func param

    
    
    

    return 0;
}
