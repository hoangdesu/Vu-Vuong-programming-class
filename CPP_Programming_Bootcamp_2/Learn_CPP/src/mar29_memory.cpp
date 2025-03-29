#include <iostream>
#include <vector>
#include <string>

using namespace std;

// static / global scope
int global = 1;
int global2 = 2;

void changeGlobal() {
    global = 2;
    cout << "Inside func = " << global << endl; // 1
}

int main(void) {
    cout << "Main = " << global << endl; // 1
    changeGlobal();
    cout << "After change = " << global << endl; // 2
    cout << "Static global = " << &global << endl;
    cout << "Static global2 = " << &global2 << endl;

    int a = 1;
    int* aPtr = &a;

    int b = 2;
    cout << "Stack aPtr = " << aPtr << endl;
    cout << "Stack bPtr = " << &b << endl;

    aPtr = new int(9); // memory leak here
    cout << "Heap aPtr = " << aPtr << endl;
    cout << "Heap *aPtr = " << *aPtr << endl;
    delete aPtr; // de-allocate to avoid memory leak

    cout << "Heap aPtr AFTER DELETE = " << aPtr << endl; // not recommended after delete
    cout << "Heap *aPtr AFTER DELETE = " << *aPtr << endl;

    // recommended to set all pointers to nullptr after deletion
    aPtr = nullptr;
    cout << "Heap aPtr AFTER nullptr = " << aPtr << endl; 
    // cout << "Heap *aPtr AFTER nullptr = " << *aPtr << endl; // will cause segmentation fault


    int& refValue = *(new int(4));
    std::cout << "refValue = " << refValue << std::endl;
    delete &refValue;


    return 0;
}
