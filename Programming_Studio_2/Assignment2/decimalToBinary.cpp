#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

string decimalToBinary(const string& decimalStr) {
    int num = stoi(decimalStr);
    if (num == 0) return "0";

    string binary = "";

    while (num > 0) {
        int remainder = num % 2;
        binary = char(remainder + '0') + binary;
        num /= 2;
    }

    return binary;
}

int main() {
    string decimal = "42";
    string binary = decimalToBinary(decimal);
    cout << "Decimal " << decimal << " = Binary " << binary << endl;

    return 0;
}
