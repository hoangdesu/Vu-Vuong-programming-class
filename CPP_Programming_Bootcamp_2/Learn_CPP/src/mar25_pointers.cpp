#include <iostream>
#include <vector>
#include <string>

using namespace std;

void changeValue(int x) {
    x = 2;
    cout << "inside x = " << x << "address = " << &x << endl; // 2
}

void changeValueUsingPointer(int* px) {
    *px = 3;
    cout << "inside x = " << *px << "address = " << &*px << endl; // 2
}

int main(void) {

    // int x = 1;
    // // changeValue(x); // changeValue(1)
    
    // changeValueUsingPointer(&x);
    // cout << "outside x = " << x << "address = " << &x << endl; // 1

    string drinks[] = {"cafe", "tea", "matcha latte", "ca phe muoi", "smoothieeeeee"};
    // start: 1 - end: 5, 6-11, 12-17...

    // int i = 0;
    // for (string drink : drinks) {
    //     cout << i++ << ". " << drink << endl;
    // }

    // int len = sizeof(drinks) / sizeof(drinks[0]);
    // for (int i = 0; i < len; i++) {
    //     cout << i+1 << ". " << drinks[i] << endl;
    // }

    // !!! ATTENTION WRONG SYNTAX: similar to drinks[0].length()
    for (int i = 0; i < drinks->length(); i++) {
        cout << i+1 << ". " << drinks[i] << endl;
    }

    // -> deference + access attribute/methods (at the same time)

    // HW: int fibonacci(int n) 

    // int fibs[n]

    // TODO: makefile

    return 0;
}
