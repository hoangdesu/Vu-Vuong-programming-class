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

    Animal animals[num_animals] {k1, k2, k3, k4, k5, t1, t2};

    // Call non-member function find_oldest_animal
    Animal* oldest = oldest_animal(animals, num_animals);

    oldest->print();
    
    return EXIT_SUCCESS;
}






