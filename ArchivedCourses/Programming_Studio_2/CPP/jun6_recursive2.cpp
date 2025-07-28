#include <iostream>
#include <string>

using namespace std;

// bool is_prime(int n) {

// }

bool is_prime(int n, int i) {
    if (n == 1) return false;
    if (n == 2) return true;

    if (n % i == 0) return false;
    if (i == n-1) return true;

    return is_prime(n, i+1);
}

// Dai dien 2 functions voi param khac nhau
void hello(string name = "user") {
    cout << "Hello " + name << endl;
}

// void hello()
// void hello(string name)

bool optimized_is_prime(int n, int i = 2) {
    if (n == 1) return false;
    if (n == 2) return true;

    if (n % i == 0) return false;
    // if (i == n-1) return true; => O(n)

    if (i * i > n) return true; // i > sqrt(n) O(sqrt(n))

    return is_prime(n, i+1);
}

int main(void) {

    // is_prime(11); // true = 1
    cout << is_prime(11, 2) << endl;
    cout << is_prime(12, 2) << endl;
    cout << is_prime(17, 2) << endl;
    cout << is_prime(20, 2) << endl;

    hello("Vuong");

    cout << optimized_is_prime(11) << endl;
    // n = 11, i = 2->10 => 9 lan
    cout << optimized_is_prime(12) << endl;
    cout << optimized_is_prime(17) << endl;
    cout << optimized_is_prime(20) << endl;


    return EXIT_SUCCESS;
}