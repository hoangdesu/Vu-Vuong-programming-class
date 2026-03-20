#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void modifyValues(int a, int *b, int &c) {
    a = 2; // copied value
    cout << "a inside: " << a << endl; // 2

    *b = 3; // deference
    cout << "*b inside: " << *b << endl; // 3
    cout << "a inside: " << a << endl; // 2

    c = 4; // direct change
}

void printFoods(string foods[], int length);

int main(void) {
    
    int a = 1;
    int *b = &a;
    // int *c =

    modifyValues(a, b, a);

    cout << "a outside: " << a << endl; // 1 -> 3 -> 4

    string foods[] = {"sushi", "takoyaki", "karaage"};

    int len = sizeof(foods) / sizeof(foods[0]);
    printFoods(foods, len);

    // this will print 5 times because first item (sushi) length is 5
    cout << "Ouside: " << endl;
    for (int i = 0; i < len; i++) {
        cout << i << ". " << foods[i] << endl;
    }


    return EXIT_SUCCESS;
}

// Array will be decayed to a pointer to first element: foods[] -> foods[0]*
void printFoods(string foods[], int length) {
    cout << "Inside print function:" << endl;
    for (int i = 0; i < length; i++) {
        cout << i << ". " << foods[i] << endl;
    }
}
