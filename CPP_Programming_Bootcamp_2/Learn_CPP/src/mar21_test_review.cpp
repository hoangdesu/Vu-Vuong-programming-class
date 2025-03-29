#include <iostream>

using namespace std;

// void ...() {
//     double loan, balance, interest_rate;
//     cin >> loan >> balance >> interest_rate;

//     int payments = 0;

//     while (balance < loan) {
//         // balance = balance + (balance * interest_rate);
//         // cout << payments << " " <<  balance << endl;
//         // payments++;

//         loan += loan * interest_rate; // Add interest
//         loan -= balance; // Apply payment
//         payments++;
//     }

//     cout << payments << " payments" << endl;
// }


bool is_prime(int n) {
    if (n == 1) return false; // edge case

    for (int i = 2; i < n-1; i++) {
        if (n % i == 0) return false;
    }
    
    return true;
}

int fibonacci(int n) {

}


int main() {
    // Prime number: số nguyên tố
    // divisible only by 1 and itself
    // => ko có số nào khác trong khoảng 2 -> n-1 có thể chia hết dc cho n

    // is prime: 7, 11, 19
    // not prime: 15, 21

    cout << is_prime(7) << endl; // 1
    cout << is_prime(15) << endl; // 0

    fibonacci(8) -> 13
    fibonacci(9) -> 21
    fibonacci(10) -> 34
    fibonacci(11) -> 55
}
