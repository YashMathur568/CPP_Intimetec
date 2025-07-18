#include <iostream>

extern int sharedValue;

extern void displaySharedValue();

int main()
{
    std::cout << "Inside main.cpp\n";
    displaySharedValue();

    std::cout << "Accessing sharedValue in main.cpp: " << sharedValue << "\n";
    return 0;
}
