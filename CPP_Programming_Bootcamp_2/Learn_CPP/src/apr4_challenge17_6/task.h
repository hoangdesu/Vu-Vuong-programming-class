#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>

class Student
{
public:
    std::string name;
    int score;

    Student(const std::string &name_val = "", int score_val = 0);

    bool operator==(const Student other);
    bool operator!=(const Student &other);
    bool operator<(const Student &other);
    bool operator>(const Student &other);

    void print();
};

#endif // TASK_H