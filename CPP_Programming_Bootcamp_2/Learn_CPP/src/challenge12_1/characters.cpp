#include "characters.h"
#include <iostream>

std::string CheckCharacter(std::string word, int index) {
    
    // 1. letter
    // 2. whitespace
    // 3. digit
    // 4. unknown

    char c = word.at(index); // word[index]

    std::string category = "Unknown: ";

    if ((c > 'a' && c < 'z') || (c > 'A' && c < 'Z')) {
        category = "Letter: ";
    } else if (c > '0' && c < '9') {
        category = "Digit: ";
    } else if (c == ' ') {
        category = "Whitespace: ";
    }

    std::string res = category + "'" + std::string(&c, &c + 1) + "'";

    return res;
}
