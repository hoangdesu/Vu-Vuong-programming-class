


// main.cpp
#include <iostream>
#include "task.h"

int main()
{
    const int num_animals = 7;

    // Declare and initialize a built-in array of Animal objects
    Animal k1("koala", "koala-la-la", 5, 5, 5);
    Animal k2("koala", "koko", 12, 2, 8);
    Animal k3("koala", "coffee", 3, 7, 0);
    Animal k4("koala", "cookie", 15, 1, 2);
    Animal k5("koala", "crumpet", 11, 0, 1);
    Animal t1("tiger", "tigger", 6, 5, 0);
    Animal t2("tiger", "trevor", 9, 6, 1); 

    Animal animals[num_animals]{k1, k2, k3, k4, k5, t1, t2};

    // Call non-member function find_oldest_animal
    Animal* oldest = oldest_animal(animals, num_animals);

    oldest->print();
    
    return EXIT_SUCCESS;
}


// task.h
#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <vector>
#include <string>

class Animal {
public:
    Animal(const std::string& = "animal", std::string = "No name", int = 0, int = 0, int = 0);
    std::string symbol();
    void print();

    std::string species;
    int age;
    std::string name;
    int x;
    int y;
};

Animal* oldest_animal(Animal*, const int);

#endif // TASK_H



//task.cpp
#include "task.h"

// oldest_animal function - Your code goes here





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




