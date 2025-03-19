#include <iostream>

using namespace std;

void print1() {
    string value = "print1";
    cout << value;
    cout << endl;
}

void print2() {
    string value = "print2";
    cout << value;
    cout << endl;
    print1();
}

void print3() {
    string value = "print3";
    cout << value;
    cout << endl;
    print2();
}

void printAll() {
    print3();
}

int main(void)  {
    int a;

    // cout << "Enter a: ";
    // cin >> a;
    // a = 5;

    // for (int i = 0; i < 3; i++) {
    //     a = a * 2;
    //     cout << "a = " << a << endl;
    // }
    

    // Debugger: tool of an editor/IDE

    // Call stack => Stack memory
    // - when a function is executed, that function is PUSHED into the callstack
    // - when the function is done, that function is POPPED out of the callstack
    // - the process is automatically done by the OS

    // print1();
    // print2();
    // print3();

    // printAll();


    // Call stack:

    // print3
    // print2
    // print1
    // main


    // Arrays
    // Perform arithmetic calculations on pointers
    long nums[] = {10, 20, 30}; // len = 3 => limit index: 0-2

    // Pointer of an array: referencing the FIRST VALUE in the array
    long *ptrNums = nums; // 0

    cout << "Address of ptr: " << ptrNums << ". Value = "; 
    cout << *ptrNums << endl; // [0]: 10

    ptrNums++; // 1
    cout << "Address of ptr: " << ptrNums << ". Value = ";
    cout << *ptrNums << endl; // [1]: 20

    ptrNums++; // 2
    cout << "Address of ptr: " << ptrNums << ". Value = ";
    cout << *ptrNums << endl; // [2]: 30

    ptrNums++; // 3 => memory overflowed
    cout << "Address of ptr: " << ptrNums << ". Value = ";
    cout << *ptrNums << endl; // [3]: ?

    // *ptrNums = "trash value" -> memory leak
    // JS, iOS, kotlin/java

    return 0;
}
