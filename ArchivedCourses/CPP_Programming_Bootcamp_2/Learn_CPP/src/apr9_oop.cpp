#include <iostream>
#include <string>

using namespace std;

class Vehicle { 
    public:
        int wheels = 4;

        void drive() {
            cout << "Vehicle driving on " << wheels << " wheels" << endl;
        }
};


// class Bike inhereting everything from class Vehicle
class Bike : public Vehicle {
    // override
    public:
        int wheels = 2;
        string materials = "carbon fiber";

        void drive() {
            cout << "Bike driving on " << wheels << " wheels" << endl;
        }

        // method overloading
        void drive(string direction) {
            cout << "Bike driving " << direction << endl;
        }
};


int main() {

    Vehicle car;
    car.drive();
    // cout << car.materials -> error

    Bike bike;
    cout << "bike has " << bike.wheels << " wheels" << endl; 
    cout << bike.materials << endl;
    bike.drive();
    bike.drive("backward");

    return 0;
}