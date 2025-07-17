#include <iostream>
#include "calc.h"

int main()
{
    int x = 5, y = 3;

    std::cout << x << " + " << y << " = " << add(x, y) << std::endl;
    std::cout << x << " * " << y << " = " << multiply(x, y) << std::endl;

    return 0;
}