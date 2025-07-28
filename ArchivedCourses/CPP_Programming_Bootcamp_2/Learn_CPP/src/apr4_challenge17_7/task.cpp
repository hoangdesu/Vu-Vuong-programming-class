//task.cpp
#include "task.h"

// oldest_animal function - Your code goes here

Animal* oldest_animal(Animal* animals, const int len) {
    // animals is NOT the array, but the pointer to the first value
    // return animals;

    if (len == 0) return nullptr;

    Animal* oldest = &animals[0];
    for (int i = 1; i < len; i++) {
        if (animals[i].age > oldest->age)
            oldest = &animals[i];
    }

    return oldest;
}


// Animal Class implementation

Animal::Animal(const std::string& in_species, std::string in_name, int in_age, int in_x, int in_y) {
    species = in_species;
    age = in_age;
    name = in_name;
    x = in_x;
    y = in_y;
}

std::string Animal::symbol() {
    std::string ret_symbol;
    if (species == "koala") 
        ret_symbol = "\xF0\x9F\x90\xA8";
    else if (species == "tiger")
        ret_symbol = "\xF0\x9F\x90\x85";
    else    
        ret_symbol = "A";
    return ret_symbol;
}

void Animal::print() {
    std::cout << name << ": " << species << " " << age << " years, (" << x << ", " << y << ")\n";
}
