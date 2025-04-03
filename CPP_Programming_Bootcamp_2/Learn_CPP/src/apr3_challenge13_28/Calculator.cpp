
#include <iostream>
#include "Calculator.h"
using namespace std;

// TODO: Define default constructor
Calculator::Calculator()
{
    this->value = 0.0;
}

// TODO: Define member functions -
//       Add(), Subtract(), Multiply(), Divide(), Clear(), GetValue()

void Calculator::Add(double val)
{
    value += val;
}

void Calculator::Subtract(double val)
{
    value -= val;
}

void Calculator::Multiply(double val)
{
    value *= val;
}

void Calculator::Divide(double val)
{
    value /= val;
}

void Calculator::Clear()
{
    value = 0.0;
}

double Calculator::GetValue()
{
    return value;
}