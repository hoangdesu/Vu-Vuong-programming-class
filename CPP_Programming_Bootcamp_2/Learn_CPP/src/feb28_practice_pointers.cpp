#include <iostream>
#include <string>

using namespace std;

// function prototypes
void swapValues(int a, int b);
void toUpperCase(string *ptrName);

int main(void) {
    // Enter a: 2
    // Enter b: 5

    // Swapped values:
    // a = 5
    // b = 2

    // string cleanupStr = removeVietnameseAccents("Thủ tướng: Việt Nam phải tăng trưởng cao liên tục tới 2045");
    // cout << cleanupStr << endl; // Thu tuong: Viet Nam phai tang truong cao lien tuc toi 2045

    string name = "brian Nguyen";
    string *ptrName = &name;
    toUpperCase(ptrName);

    cout << name << endl; // => BRIAN NGUYEN

    cout << "Address: " << ptrName << endl;

    // Pointer is just another variable. Its address can be changed
    string car1 = "lamborghini";
    string car2 = "ferrari";

    string *favCar = &car1;

    cout << *favCar << endl; // lambo

    favCar = &car2; 

    cout << *favCar << endl; // ferrari

    *favCar = "mclaren"; // *favCar => car2 => car2 = "mclaren"
    car2 = "mercedes";

    cout << "car2=" << car2 << " - *favCar=" << *favCar << endl; // mercedes

    return 0;
}

void toUpperCase(string *ptrName) {
    // -> deference + access
    // ptrName->length() == (*ptrName).length()

    for (int i = 0; i < ptrName->length(); i++) {
        // cout << i << ". " << ptrName->at(i) << endl;
        char c = ptrName->at(i); // (*ptrName).at(i) || (*ptrName)[i]
        
        if (c >= 'a' && c <= 'z') {
            char upperC = c - ('a' - 'A'); // 97 - 65 = 32 -> avoid magic numbers
            (*ptrName)[i] = upperC;
        }
    }
}
