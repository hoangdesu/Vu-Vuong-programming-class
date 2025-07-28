#include <iostream>
#include "task.h"

int main()
{
    Student s1("Julie", 85);
    Student s2("Sheryl", 92);
    Student s3("Michael", 92);

    std::cout << "\nTest == and !=\n";
    if (s1 == s1)
    {
       s1.print();
       std::cout << " equal ";
       s1.print();
       std::cout << "\n";
    }
    if (s1 != s2)
    {
       s1.print();
       std::cout << " NOT equal ";
       s2.print();
       std::cout << "\n";
    }

    std::cout << "\nTest < > \n";
    if (s2 > s1)
    {
       s2.print();
       std::cout << " has a higher score than ";
       s1.print();
       std::cout << std::endl;
    }
    if (s1 < s2)
    {
       s1.print();
       std::cout << " has a lower score than ";
       s2.print();
       std::cout << std::endl;
    }

    if (s2 > s3)
    {
        s2.print();
        std::cout << " has a higher score than ";
        s3.print();
        std::cout << "\n";
    }
    else if (s2 < s3)
    {
        s2.print();
        std::cout << " has a lower score than  ";
        s3.print();
        std::cout << "\n";
    }
    else
    {
        s2.print();
        std::cout << " and  ";
        s3.print();
        std::cout << " have the same score";
        std::cout << "\n";
    }

    std::cout << "\n";

    return EXIT_SUCCESS;
}






