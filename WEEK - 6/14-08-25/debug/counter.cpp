#include "counter.h"
#include <iostream>

Counter::Counter() : value(0) {}

void Counter::increment()
{
    value++;
}

void Counter::display()
{
    std::cout << "Value: " << value << std::endl;
}