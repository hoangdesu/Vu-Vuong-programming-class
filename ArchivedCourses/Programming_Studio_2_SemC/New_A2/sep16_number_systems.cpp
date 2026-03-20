#include <iostream>
#include <string>

using namespace std;

string decimal_to_binary(int num) {
    string res = "";

    while (num != 0) {
        int binary = num % 2;
        res = to_string(binary) + res;
        // res.insert(0, to_string(binary));
        num /= 2;
    }

    return res;
}


int binary_to_decimal(string bin) {
    int counter = 1;

    int res = 0;

    for (int i = bin.size() - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            res += counter;
        }

        counter *= 2;
    }

    return res;
}


int main(void)
{
    cout << "12 = " << decimal_to_binary(12) << endl; // 12 = 1100
    cout << "237 = " << decimal_to_binary(237) << endl; // 12 = 1100
    cout << "1011 = " << binary_to_decimal("1011") << endl; // 1010 = 11
    cout << "1100 = " << binary_to_decimal("1100") << endl; // 1100 = 12

    return EXIT_SUCCESS;
}