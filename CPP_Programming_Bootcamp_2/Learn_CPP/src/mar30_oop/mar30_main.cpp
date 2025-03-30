#include <iostream>
#include <string>

#include "food.h"

using namespace std;

int main() {

    // Creating a new Food object
    Food pizza("pizza", 4); // object pizza is created on the Stack memory
    pizza.printFood();
    pizza.printRating();
    pizza.printRating(10);
    cout << "&pizza = " << &pizza << endl;
    
    
    // Java: Food pizza = new Food("Pizza", 1);
    Food* sushi = new Food("sushi", 5); // pointer to sushi object is created on the Heap memory
    sushi->printFood(); // arrow syntax -> deference and access class members at the same time
    (*sushi).printFood();
    cout << "addr sushi: " << sushi << endl;
    

    // deleting objects on the heap when done
    delete sushi;
    sushi = nullptr;

    // if sushi is deleted, memory is freed and reused for next object
    
    // using the & syntax
    Food& ramen = *(new Food("ramen", 5)); // object ramen is placed on the Heap
    ramen.printFood();
    ramen.printName();
    cout << "addr ramen: " << &ramen<< endl;

    delete &ramen;


    // TODO: 
    // - fix this constructor overloading bug
    // - Slide 6 class 1
    Food pho;
    pho.printFood();

    return EXIT_SUCCESS;
}