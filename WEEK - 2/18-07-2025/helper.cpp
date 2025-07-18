#include <iostream>

int sharedValue = 42;
void displaySharedValue()
{
    std::cout << "Inside helper.cpp - sharedValue is: " << sharedValue << "\n";
}
