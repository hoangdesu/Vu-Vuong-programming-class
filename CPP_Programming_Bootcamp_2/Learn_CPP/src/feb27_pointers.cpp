#include <iostream>

using namespace std;

void changeValue(int x) {
    x = 100;
    cout << "Inside function x = " << x << endl;
}

void changeValueUsingPointer(int *pX) {
    // pX: address
    // must DEFERENCE before directly accessing the value at such address

    *pX = 200;
}

int main(void) {

    // Pointers 

    // RAM: random-access memory

    // memory address of a variable must be computed by a Hash Algorithm

    int a = 2;
    a = 5;
    // int b = 9;

    cout << "value of a = " << a << endl; // 1

    // extracting the memory address of a using the ampersand &
    cout << "address of a in memory using & = " << &a << endl; // something like: 0x16d712738

    // pointer: is a variable that stores the memory address as its value.
    // creating a pointer: place an asterisk *: AFTER a data type Or BEFORE a variable name
    int *pA = &a; // pointer to the memory address of value a

    cout << "address of a in memory using pointer *pA = " << pA << endl;

    // deference: *
    cout << "deference the value at the pointer A = " << *pA << endl;


    // Example

    int x = 1; 
    changeValue(x); // -> changeValue(1) => passing a copied value
    cout << "Outside function x = " << x << endl;

    int *px = &x;
    changeValueUsingPointer(px); // -> changeValue(x) => passing a variable
    // tương đương với: changeValueUsingPointer(&x)
    // changeValueUsingPointer(&x);
    cout << "After chaning value using pointer x = " << x << endl;

    
    cout << " a = " << a << endl;
    cout << " &a = " << &a << endl; // referencing
    cout << " *&a = " << *&a << endl; // dereferencing
    cout << " &*&*&*&*&a = " << &*&*&*&*&a << endl;
    cout << " *&*&*&*&*&a = " << *&*&*&*&*&a << endl;
    

    // char msg[] = {'H', 'e', 'l', 'l', 'o', '\0'}; -> string 

    return 0; // successful execution code = 0
}