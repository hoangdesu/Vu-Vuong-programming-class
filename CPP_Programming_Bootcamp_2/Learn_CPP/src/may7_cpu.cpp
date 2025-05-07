#include <iostream>

using namespace std;

#define LC3 "Little Computer 3" // macro

int main() {
    string name = "Vuong";
    name = "Vu Vuong";
    cout << name << endl;

    // LC3 = "LC3"; // error
    cout << LC3 << endl;

    // string -> char[]

    return EXIT_SUCCESS;
}


1100
8421 = 8 + 4 = 12

Bitwise Operations:

Right shift 1 = divided by 2
1100 >> 1
0110
8421 = 4 + 2 = 6

Left shift 1: 2 cases

1100 << 1
case1 - maintain no. bits (losing values)
1000 = 8

case2 - use extra bits (multiply by 2)
11000 = 24


NOT R1 , R1 ; R1 ← NOT( R1 )
3 NOT R2 , R2 ; R2 ← NOT( R2 )
4 AND R3 , R1 , R2 ; R3 ← NOT( R1 ) AND NOT( R2 )
5 NOT R3 , R3 ; R3 ← R1 OR R2

if (mem & opit) // OR
{
	if (imm_flag) {
		reg[r1] = !reg[r1]	;
		reg[r2] = !reg[r2];
		reg[r3] = !reg[r1] & !reg[r2];		
        reg[r3] = !reg[r3];
		
	}
}