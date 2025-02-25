#include <iostream>
#include <string>

using namespace std;

// Function prototypes
void hi(string name);
bool isPrimeNumber(int num);

int main(void) {

    string car1 = "ferrari";
    string car2 = "ferrari";

    cout << car1.compare(car2) << endl; // not true or false => 0 or 1
    // 0: true
    // >=1: false

    string car3 = "Ferrari";
    cout << car1.compare(car3) << endl;

    // for (int i = 0; i < 3; i++) {
    //     cout << i << endl;
    // }

    // int i = 0;
    // while (i < 3) {
    //     cout << i << endl;
    //     i++;
    // }

    // int i = 0;
    // while (true) {
    //     cout << i << endl;
    //     i++;
    //     if (i == 3) break;
    // }
    

    // functions
    // hi("Vuong");

    // num =  Enter a number: 7

    // isPrimeNumber(num) -> true / false

    // 7 is a prime number
    cout << "isPrimeNumber 7: " << isPrimeNumber(7) << endl; // 1 = true
    cout << "isPrimeNumber 8: " << isPrimeNumber(8) << endl; // 0 = false

    
    cout << "Enter a number: ";
    int num;
    cin >> num;
    if (isPrimeNumber(num)) {
        cout << num << " is a prime number\n";
    } else {
        cout << num << " is NOT a prime number\n";
    }

    
    return 0;
}

// Function definitions
void hi(string name) {
    cout << "Hi " << name << endl;
}


// số nguyên tố: chỉ chia hết cho 1 và chính nó
// - 1 is not a prime number
// - 2 is the only even prime number
// - eg: 3, 7, 11, 19, 17, 23


// input: 7
// chi chia het cho 1 va chinh no
// => co so nao khac trong khoang tu 2 -> num-1 ma chia het cho num hay ko?
// [2 3 4 5 6]

bool isPrimeNumber(int num) {
    // early return for edge case
    if (num == 1) return false;

    // for (int n = 2; n < num; n++) {
    //     if (num % n == 0) return false;
    // }

    int n = 2;
    while (n < num) {
        if (num % n == 0) return false;
        n++;
    }

    return true;
}





