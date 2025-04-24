#include "Task.h"
#include <vector>

using namespace std;

std::vector<int> getMultiplesInRange(int num, int lower_bound, int upper_bound) {
   vector<int> result;
   
//    if ( num > 0 || lower_bound > upper_bound ) {
//       result.push_back(lower_bound);
//       for (int i = lower_bound; i < upper_bound;) {
      
//       i = i + num;
      
//       result.push_back(i);
//       }
//       } else { return result;
//    }

    for (int n = lower_bound; n <= upper_bound; n++) {
        if (n % num == 0) result.push_back(n);
    }
   
   return result;
}