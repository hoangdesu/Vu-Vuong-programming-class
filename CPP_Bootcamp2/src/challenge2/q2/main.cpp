#include <iostream>
#include <string>

using namespace std;

string format_double(double value, int fieldWidth, int precision) {
    string val = to_string(value);

    // "123.456" -> 2
    string formatVal = "";
    int i = 0;
    while (i < val.length()) {
        if (val[i] != '.') {
            formatVal += val[i];
            i++;
        } else {
            formatVal += '.';
            i++;

            for (int j = 0; j < precision; j++) {
                formatVal += val[i];
                i++;
            }

            break;
        }
    }

    int space_len = fieldWidth - formatVal.length();

    string finalStr = "";
    for (int i = 0; i < space_len; i++) {
        finalStr += " ";
    }

    finalStr += formatVal;

    return finalStr;
}

int main(void) {

    // string s = "        In      C++,    obtaining     or     controlling     the    number    of     decimal places for floating-point numbers"
    cout << format_double(123.456, 10, 2); // "     123.45"

    return EXIT_SUCCESS;
}