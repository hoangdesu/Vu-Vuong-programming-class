#include <iostream>
#include "Triangle.h"

using namespace std;

int main() {
   Triangle triangle1;
   Triangle triangle2;

   double base, height;
   // TODO: Read and set base and height for triangle1 (use SetBase() and SetHeight())
   cin >> base >> height;
   triangle1.SetBase(base);
   triangle1.SetHeight(height);
      
   // TODO: Read and set base and height for triangle2 (use SetBase() and SetHeight())
   cin >> base >> height;
   triangle2.SetBase(base);
   triangle2.SetHeight(height);

   cout << "Triangle with smaller area:" << endl;

//    Triangle smallerTriangle;

//    using ternary
   triangle1.GetArea() < triangle2.GetArea() ? triangle1.PrintInfo() : triangle2.PrintInfo();

//    using simple if-else
    // if (triangle1.GetArea() < triangle2.GetArea()) {
    //     smallerTriangle = triangle1;
    // } else {
    //     smallerTriangle = triangle2;
    // }

    // smallerTriangle.PrintInfo();

   // TODO: Determine smaller triangle (use GetArea())  
   //       and output smaller triangle's info (use PrintInfo())
   
   return 0;
}
