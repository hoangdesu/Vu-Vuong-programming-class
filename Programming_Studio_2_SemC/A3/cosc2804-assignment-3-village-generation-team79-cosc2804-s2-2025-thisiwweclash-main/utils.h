#ifndef UTILS_H
#define UTILS_H

#include <iostream>

void print_student_details() {
    std::cout << "Student 1 - Task A: [Name] - [Number] - [GitHub Username] " << std::endl ;
    std::cout << "Student 2 - Task B: [Name] - [Number] - [GitHub Username] " << std::endl ;
    std::cout << "Student 3 - Task C: [Name] - [Number] - [GitHub Username] " << std::endl ;
}

void print_command_line_arguments(int loc_x, int loc_z, int village_size, int plot_border, int seed, bool testmode) {
    std::cout << "Command Line Arguments: " << std::endl ;
    std::cout << "\t Location (x,z) : (" << loc_x << ", " << loc_z << ")" << std::endl ;
    std::cout << "\t Village Size : " << village_size << std::endl ;
    std::cout << "\t Plot Border : " << plot_border << std::endl ;
    std::cout << "\t Seed : " << seed << std::endl ;
    std::cout << "\t Testmode : " << testmode << std::endl ;
}

#endif