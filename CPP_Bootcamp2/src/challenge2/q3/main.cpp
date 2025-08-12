#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string repeatChar(const char* c, int count) {
    if (count < 0 || c == nullptr)
    {
        return "";
    }

    // string s = "";
    // string is array of chars
    // => array is on stack memory: speed ⬆️ vs space ⬇️

    ostringstream stringBuilder;
    // buffer -> heap: speed ⬇️ vs space ⬆️

    for (int i = 0; i < count; i++)
    {
        // s += c;
        stringBuilder << c;
    }

    return stringBuilder.str();
}

int main(void) {
    char char1 = 'x';
    int count1 = 5;

    cout << repeatChar(&char1, count1) << endl;

    char1 = 'y';
    count1 = -1;

    cout << repeatChar(&char1, count1) << endl;

    char *char2 = nullptr;
    count1 = 5;

    cout << repeatChar(char2, count1) << endl;


    return EXIT_SUCCESS;
}