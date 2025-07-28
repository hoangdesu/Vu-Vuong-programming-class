#include <iostream>

using namespace std;

// namespace: create a scope to contain a set of variables and methods
// :: scope resolution operator
// no need to create object from namespace

namespace A {
    int x = 1;

    void printX() {
        cout << "Scope A: " << x << endl;
    }
}

namespace B {
    int x = 2;

    void printX() {
        cout << "Scope B: " << x << endl;
    }
}

class C {
    // int x = 3; // private
    public:
        int x = 3;
        const static int y = 4;
};

// nested namespaces
namespace D {
    namespace D1 {
        namespace D11 {
            int x = 5;
        }
    }

    namespace D2 {
        namespace D21 {
            int x = 6;
        }
    }
}

// only from C++ 17 above, this new syntax is supported
namespace E::E1::E2 {
    string name = "inside namespace E2";
}

// unnamed namespace 
namespace {
    string n_space = "calling from unnamed namespace";
}

using namespace B;

int main(void) {
    cout << A::x << endl;
    cout << B::x << endl;

    A::printX();
    B::printX();

    C cObject; // must create an object from the class
    cout << cObject.x << endl; // and access the attribute through the object
    cout << cObject.y << endl;
    cout << C::y << endl; // can access this static var directly from a class

    cout << D::D1::D11::x << endl;
    cout << E::E1::E2::name << endl;

    cout << n_space << endl;
    cout << "x = " << A::x << endl;

    return 0;
}


// struct: TODO