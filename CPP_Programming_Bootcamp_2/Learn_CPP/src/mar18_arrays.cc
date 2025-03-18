#include <iostream>

using namespace std;

void print_array(string arr[], int arr_len) {
    // cout << "Printing array inside print_array function: " << arr << endl;
    
    // when passing an array to a function, the function will automatically DECAY the array into a pointer
    // error: "warning: sizeof on array function parameter will return size of 'string *' (aka 'basic_string<char> *') instead of 'string[]' (aka 'basic_string<char>[]') [-Wsizeof-array-argument]"
    cout << "PRINT_ARRAY sizeof(drinks): " << sizeof(arr) << endl;

    // cannot get the array length inside a function
    // => work-around: must also pass the array length as function param
    // cout << "PRINT_ARRAY array's length: " << sizeof(arr) / sizeof(arr[0]) << endl;

    cout << "INSIDE FUNCTION: " << endl;
    for (int i = 0; i < arr_len; i++) {
        cout << i << ". " << arr[i] << endl;
    }
}

int main(void) {
    string drinks[] = {"coffee", "tea", "matcha latte", "ca phe muoi", "smoothie"};

    // cout << drinks[0];

    cout << "MAIN sizeof(drinks): " << sizeof(drinks) << endl;

    cout << "array's length: " << sizeof(drinks) / sizeof(drinks[0]) << endl;

    int drinks_len = sizeof(drinks) / sizeof(drinks[0]);

    for (int i = 0; i < drinks_len; i++) {
        cout << i << ". " << drinks[i] << endl;
    }

    cout << "Printing array inside main: " << drinks << endl;
    print_array(drinks, drinks_len);

    return 0;
}