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