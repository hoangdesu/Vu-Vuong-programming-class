#include <iostream>

using namespace std;

class Human {
    public:
        Human(string fname) {
            this->firstName = fname;
        }

        Human(string fname, string lname) {
            firstName = fname;
            lastName = lname;
        }

        bool equals(Human h) {
            if (firstName == h.firstName && lastName == h.lastName) return true;
            else return false;
        }

        // operator overloading as a member function
        bool operator == (Human& h2) {
            return firstName == h2.firstName && lastName == h2.lastName;
        }

        void printName() {
            cout << (firstName + " " + lastName) << endl;
        }

        // friend Human& operator += (Human& h, const string& lname);
        Human& operator += (const string& lname) {
            lastName += lname; // Append lname to lastName
            return *this; // Return a reference to the current object
        }

        void setLastname(string lname) {
            lastName = lname;
        }

    private:
        string firstName;
        string lastName;
};

// Human& operator += (Human& h, string& lname) {
//     // h.lastName = lname;
//     h.setLastname(lname);
//     return h;
// }

int main()
{
    Human human1("Vuong", "Nguyen");
    Human human2("Vuong", "Nguyen");

    Human human3("Brian");
    human3 += "Nguyen";
    human3.printName();

    // human1 == human2;
    // cout << human1.equals(human2) << endl;
    cout << (human1 == human2) << endl;

    return 0;
}
