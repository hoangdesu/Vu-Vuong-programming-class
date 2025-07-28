#include <iostream>

using namespace std;

bool is_isbn_valid(string isbn) {
    // if (isbn.length() != 10 || isbn.length() != 13) return false;

    bool trippled = false;

    int sum = 0;
    int counter = 0;
    for (int i = 0; i < isbn.length() - 1; i++) {
        char ch = isbn[i];
        if (ch >= '0' && ch <= '9') {
            int valOfChar = ch - '0';
            // cout << valOfChar << '.';
            // if (trippled) valOfChar *= 3;

            if (counter % 2 == 1) valOfChar *= 3;

            sum += valOfChar;
            // trippled = !trippled;
            counter++;
        }
    }

    // cout << endl << "sum:" << sum << endl;

    int checkDigit = 10 - (sum % 10);
    int lastDigit = isbn.at(isbn.length() - 1) - '0';

    return checkDigit == lastDigit;
}

int main(void) {
    // ISBN 13 digit
    cout << endl << "valid?: " << is_isbn_valid("9780-306-40615-7") << endl; // true->1
    cout << endl << "valid?: " << is_isbn_valid("9780306406157") << endl; // true->1
    cout << endl << "valid?: " << is_isbn_valid("978030640615-7") << endl; // true->1
    cout << endl << "978-0134685991 valid?: " << is_isbn_valid("978-0134685991") << endl; // true->1
    cout << endl << "valid?: " << is_isbn_valid("9780-306-40615-8") << endl; // false->0

    // ISBN 10 digit
    cout << endl << "valid?: " << is_isbn_valid("0-306-40615-2") << endl; // true->1 
    cout << endl << "0134685997 valid?: " << is_isbn_valid("0134685997") << endl; // true->1 
    cout << endl << "valid?: " << is_isbn_valid("0-306-40615-3") << endl; // false->0


    // for1 char in "9780-306-40615-7" 
    // -> for2 char in "9780306406157"

    //                 i 
    //     c
    //  0123 456 78901
    // "9780-306-40615-7" 


    HOMEWORK: extend the same function to support ISBN10

    return 0;
}