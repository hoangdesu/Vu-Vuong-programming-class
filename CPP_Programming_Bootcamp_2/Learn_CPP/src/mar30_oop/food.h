// header guards
#ifndef FOOD_HEADER
#define FOOD_HEADER

#include <iostream>
#include <string>

using namespace std;

class Food {
    public:
        // constructor overloading
        // Food();
        Food(string name);
        Food(string name = "rice", int rating = 0);
        
        void printFood();

        // not recommended. put implementation in cpp file
        void printName() {
            cout << "printing name from header: " << name << endl;
        };

        // method overloading
        void printRating();
        void printRating(int scale);

    private:
        string name;
        int rating;

};

#endif