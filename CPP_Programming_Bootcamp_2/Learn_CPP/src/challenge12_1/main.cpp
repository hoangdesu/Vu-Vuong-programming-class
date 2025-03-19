#include <iostream>

// custom header, must have the .h extension
#include "characters.h"

int main(void) {
    
    std::cout << CheckCharacter("happy birthday", 2) << std::endl; // "p"
    std::cout << CheckCharacter("happy birthday", 5)<< std::endl; // space
    std::cout << CheckCharacter("happy birthday 2 you", 15) << std::endl; // 2
    std::cout << CheckCharacter("happy birthday!", 14) << std::endl; // !

    return 0;
}
