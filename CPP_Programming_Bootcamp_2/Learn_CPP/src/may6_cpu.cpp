#include <iostream>

using namespace std;

int main() {

    cout << 1 + 2 << endl; // value 3 is stored in the accumulator

    int a = 4 + 5; 
    // 1. 4 + 5 => acc
    // 2. mov acc R -> move value from acc to a memory in RAM, and refer to it as "a"

    if true {
        do this
    } else {
        do that
    }

    return EXIT_SUCCESS;
}
