#include <iostream>
#include <string>

using namespace std;

class Student {
    public:
        // class attributes: encapsulated using private
        string first_name;
        string last_name;


        // Constructors + constructor overloading
        Student() {} // default constructor

        Student(string fname, string lname) {
            first_name = fname;
            last_name = lname;
        }

        Student(string fname, string lname, double gpa) {
            first_name = fname;
            last_name = lname;
            this->gpa = gpa;
        }


        // methods
        void printStudent() {
            cout << "Student name: " << first_name + " " + last_name << endl;
        }

        // getters / setters
        double getGPA() {
            return this->gpa; // similar to "return gpa;"
        }

        void setGPA(double gpa) {
            this->gpa = gpa;
        }

        int getStartYear() {
            return this->startYear;
        }

    private:
        double gpa = 0.0;
        int startYear = 2025;
        
};


int main() {

    Student vuong; // on stack memory
    vuong.first_name = "Vương";
    vuong.last_name = "Nguyễn";
    vuong.printStudent();

    vuong.setGPA(4.9);
    cout << "GPA: " << vuong.getGPA() << endl;
    cout << "Start year: " << vuong.getStartYear() << endl; 


    Student justin("Justin", "Bieber"); // stack
    justin.printStudent();


    Student* vuongHeapPtr = new Student("Vuong", "Nguyen"); // heap
    // (*vuongHeapPtr).printStudent();
    vuongHeapPtr->printStudent();

    Student& brianHeap = *(new Student("Brian", "Nguyen", 3.1));
    cout << "Brian GPA: " << brianHeap.getGPA();



    return 0;
}


// Access modifiers in C++:
// - public
// - protected
// - private: default


// 4 characteristics of OOP:
//     1. Encapsulation: tính đóng gói
//     2. Inheritance: tính kế thừa
//     3. Abstraction: tính trừu tượng => interface
//         giúp dev ko cần quan tâm đến implementation phía sau
//         chỉ focus vào phần logic
//     4. Polymorphism: poly-nhiều (đa), morph-hình => tính đa hình


// Always go for the naive approach first
// Refactor and optimize code later


// class Chimpanzee {
//     void eat() {
//         chimpanzee eats banana
//     }
// }

// chimpanzee.eat() -> banana

// class Human inherits Chimpanzee {
//     void eat() {
//         human eats rice
//     }
// }

// human.eat() -> rice


// // God creates the world
// class Species {
//     eat();
// }


// Constructor: 
// - special method(s) used to build objects from a class
// - share the same name with the class
// - no return type
// - if no constructor defined, C++ will give u a default constructor with 0 param
// - can be overloadded