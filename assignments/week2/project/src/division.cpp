#include "../include/division.h"
#include <stdexcept>

double divide(double a, double b)
{
    if (b == 0)
        throw std::runtime_error("Cannot divide by Zero\n");
    return a / b;
}