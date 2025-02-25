#include <iostream> // header file: library for input/output stream

/* multi
line
comment 
*/

// std: standard namespace

using namespace std;

int main()
{
    // std: using standard character output stream
    std::cout << "Hello " << "world =))))\n" << std::endl << "This is a new line!"; // \n
    // std::cout << "This is a new line!";


    // while (1) {}

    // namespace: exported identifier from iostream lib 
    // iostream.cout
    // iostream -> std


    // Java: ham dc chua o 1 class nao do: System.out.println()

    cout << endl << "no longer need to use std to output" << endl;
    

    int a, b;

    cout << "\nEnter number a: ";
    cin >> a;
    cout << "\Enter number b: ";
    cin >> b;

    int c = a + b;
    cout << a << " + " << b << " = " << c << endl;


    return 0; // 0: status code for NO ERROR
}
