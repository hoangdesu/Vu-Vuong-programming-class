#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string removeVietnameseAccents(string s) {
    return "";
}

int main() {

    // Basic data types:
    // int, float, double, char, bool, long, short

    // signed vs unsigned

    // 1 bit: 0 || 1 => 2 numbers
    // 2 bits: 00, 01, 10, 11 => 4 numbers
    // 3 bits: 000, 001, 010, 100, 011, 110, 101, 111 => 8 numbers
    // 4 bits: 16 numbers
    // n bits: 2^n max numbers
    // int = 4 bytes = 32 bits => 2^32 => 4.29B
    // => half for negative, half for positive
    // -2.1B -> 0+2.1B

    // world population: 8B

    // signed: có dấu

    // half of world population: 4B < max int value

    // sử dụng hết khả năng lưu trữ của thằng int 4.1B => uint

    // unsigned variables: prefix with u_... u_int16_t, uint_fast32_t

    // char vs String
    // string: array of characters -> string.toCharArray()

    string name = "Justin";
    name = "Vuong";

    cout << "Vu " + name << endl;

    // boolean
    cout << (1 > 5) << endl; // false
    cout << (5 > 1) << endl; // true
    

    // float vs double
    int a = 1;
    float b = 2.2;
    double c = 3.3;

    cout << a + b * c << endl;


    // Character
    // represented by an ascii value

    char letterA = 65; // ascii
    cout << letterA << endl;

    // Operators: 
    // + addition (string concatenation / concat)
    // - 
    // *
    // /

    // +=, -=, ++a, a++, %, /=

    // BITWISE operators
    // &=, |=, ^=, >>=, <<=
    
    
    // cout << pow(b, c);


    // s = ''
    // for i in range(len(val)):
    //     s += val[i]


    // Comparisons: ==, != >=, <=, >, <
    // Combining boolean expressions: &&, ||, !


    // Strings
    cout << "What's your name: ";
    // String name = sc.nextLine(); \n
    string myName;
    // cin >> myName;
    
    // cin treats a WHITE SPACE as a terminating char
    // getline(cin, myName); // cin >> myName

    // cout << "Hello " << myName << endl;

    string country = "vietnam"; // -> "Vietnam" // => country[0] = 'V'
    string people = country.append("ese"); // country + "ese"
    

    cout << "I am " + people << endl;
    cout << country.at(0) << endl; // .charAt(index)

    string x = "10";
    string y = " 20";
    int z = 30;

    cout << x + y << endl;
    cout << x << y << endl;
    // cout << x + z; // error

    // get the str length:
    cout << "size():" << country.size() << " - length():" << country.length() << endl;


    // string: array of chars -> use index to access a single char

    cout << "country[0]:" << country[0] << ", string.at(0): " << country.at(0) << endl;

    for (int i = 0; i < country.length(); i++) {
        cout << i << ":" << country[i] << endl;
    }

    // C++: C with classes
    // string in C: allocate a certain amount of memory before hand
    char car1[] = "Mercedes"; // 9 => including the string terminate character '\0'
    string car2 = "Mercedes"; // 8

    cout << "Size of car1: " << sizeof(car1) << endl;
    cout << "Size of car2: " << car2.length() << endl;

    for (int i = 0; i < sizeof(car1); i++) {
        cout << i << ":" << car1[i] << endl;
    }

    char futureCar[5];
    cout << "What's your dream car: ";
    cin >> futureCar;

    cout << futureCar << endl;

    for (int i = 0; i < sizeof(futureCar); i++) {
        cout << i << ":" << futureCar[i] << endl;
    }

    // ----
    // HW:

    // strings in C++ are MUTABLE
    // strings in Java are IMMUTABLE

    country[0] = 'V';
    cout << country;

    // cout << removeVietnameseAccents("Thủ tướng: Việt Nam phải tăng trưởng cao liên tục tới 2045") // Thu tuong: Viet Nam phai tang truong cao lien tuc toi 2045
    // hint: conditionals if-else / switch-case

    return 0;
}