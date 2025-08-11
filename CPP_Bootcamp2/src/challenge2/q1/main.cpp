#include "task.h"
#include <iostream>

using namespace std;
 
int main() {
   Time start(02, 55, 10);  // Start time: 02:55:10
   Time end(04, 15, 50);    // End time: 04:15:50
   Time difference;

   cout << start.GetHours() << end.GetMinutes() << endl;

   difference.TimeDifference(end, start);

   std::cout << "Difference: " << difference.GetHours() << ":" << difference.GetMinutes()
      <<  ":" << difference.GetSeconds() << std::endl;


    Time start2(02, 15, 50);
    Time end2(02, 10, 40);
    Time difference2;

    
    difference2.TimeDifference(end2, start2);
    cout << "Diff 2: " << difference2.GetHours() << ":" << difference2.GetMinutes() << ":" << difference2.GetSeconds() << endl;

   return EXIT_SUCCESS;
}