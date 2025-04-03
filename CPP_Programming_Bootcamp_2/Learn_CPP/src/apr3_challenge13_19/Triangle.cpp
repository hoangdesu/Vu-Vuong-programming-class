#include "Triangle.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void Triangle::SetBase(double userBase) const {
   base = userBase;
}

void Triangle::SetHeight(double userHeight) {
   height = userHeight;
}

double Triangle::GetArea() const {
    // base = base * 2; // cannot modify class attribute due to const
   return 0.5 * base * height;
}

void Triangle::PrintInfo() const {
   cout << fixed << setprecision(2);
   cout << "Base: " << base << endl;
   cout << "Height: " << height << endl;
   cout << "Area: " << GetArea() << endl;
}
