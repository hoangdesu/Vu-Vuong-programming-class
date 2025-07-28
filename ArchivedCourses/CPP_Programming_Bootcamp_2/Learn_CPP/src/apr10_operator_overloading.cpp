#include <iostream>

using namespace std;

class Num {
    public:
        // constructor
        Num() {}

        Num(int n) {
            // cout << "before assigning: " << this->n;
            this->n = n;
            // cout << "after assigning: " << this->n;
        }

        void print() {
            cout << n << endl;
        }

        // operator overloading: +
        // member-function
        Num operator+ (const Num& otherNum) {
            Num res(this->n + otherNum.n);
            return res;
        }
        
        Num operator+ (string numStr) {
            int num = 0;
            if (numStr == "one") {
                num = 1;
            }
            Num res(this->n + num);
            return res;
        }

        // not recommended
        // void operator<< (string whatever) {
        //     cout << this->n << endl;
        // }

        // using friend functions to access private fields
        friend ostream & operator<< (ostream &output, const Num &num);
        friend istream & operator>> (istream &input, Num &num);
        friend Num times(const Num& num, int times);
        friend class Debugger;

    private:
        int n;
};


// Non-member operator overloading
ostream& operator<< (ostream &output, const Num &num) {
    output << num.n << endl;
    return output;
}

istream & operator>> (istream &input, Num &num) {
    cout << "Enter value: ";
    input >> num.n;
    return input;
}

// non-member function
Num times(const Num& num, int times) {
    Num res(num.n * times);
    return res;
}

// friend class
class Debugger {
    public:
        void log(const Num& num) {
            cout << "[DEBUG] n = " << num.n << endl;
        }
};


int main() {

    Num a(1);
    Num b(2);

    cout << times(b, 3);

    // a.print(); thuần OOP

    Num c = a + b;
    c.print();

    Num d(10);
    d.print();
    Num e = d + "one";

    // cout << e << endl;
    // e << "hi"; // not good practice

    // stream out << values;   insertion
    // stream in >> values;    extraction

    cout << e << b << a;

    Num f;
    cin >> f;
    cout << "f = " << f;

    Debugger debugger;
    debugger.log(f);

    // f.log??

    return EXIT_SUCCESS;
}
