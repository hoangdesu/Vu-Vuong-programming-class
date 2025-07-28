#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

string binaryToDecimal(const string& binaryStr) {
    int num = 0;
    for (char c : binaryStr) {
        if (c != '0' && c != '1') {
            throw invalid_argument("Invalid binary digit");
        }
        num = num * 2 + (c - '0');
    }
    return to_string(num);
}

int main() {
    string binary = "101010"; // decimal = 42
    string decimalResult = binaryToDecimal(binary);
    cout << "Binary " << binary << " = Decimal " << decimalResult << endl;

    return 0;
}
