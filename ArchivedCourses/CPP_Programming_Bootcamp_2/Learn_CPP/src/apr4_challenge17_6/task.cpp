#include <iostream>
#include <string>

#include "task.h"

using namespace std;

Student::Student(const std::string &name_val, int score_val) {
    name = name_val;
    score = score_val;
}

bool Student::operator == (const Student &other) {
    return name == other.name;
}

bool Student::operator != (const Student &other) {
    return name != other.name;
}

bool Student::operator < (const Student &other) {
    return this->score < other.score;
}

bool Student::operator > (const Student &other) {
    return this->score > other.score;
}

void Student::print() {
    cout << name;
}