#include <iostream>
#include <string>

using namespace std;

class ProgrammingLanguage {
    public:
        ProgrammingLanguage(string name) {
            this->name = name;
        }

        void print() {
            cout << "Language: " << this->name << endl;
        }

        static void manual() {
            cout << "Construct an object with the name of a programming language" << endl;
        }

        // destructor: called when an object is deleted
        // ~ProgrammingLanguage() {
        //     delete &name;
        //     delete &year;
        //     cout << "Deleted object!" << endl;
        // }

        void setYear(int year) {
            this->year = year;
        }

        int getYear() {
            return this->year;
        }
    
    private:
        string name;
        int year;
        
};

int main() {

    ProgrammingLanguage cpp("C++");
    cpp.print();
    cout << "CPP year: " << cpp.getYear() << endl;

    // delete cpp; // goes out of scope


    ProgrammingLanguage::manual(); // :: scope resolution operator

    // copy object: modifying this object will NOT affect the original object
    ProgrammingLanguage cp = cpp;

    cout << "Printing object cp: ";
    cp.print();
    cp.setYear(1979);

    cout << "CPP year: " << cpp.getYear() << endl;
    cout << "CP year: " << cp.getYear() << endl;


    return EXIT_SUCCESS;
}
