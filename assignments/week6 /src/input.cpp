#include <iostream>
#include "input.h"

void flushInputBuffer()
{
    while (getchar() != '\n')
    {
    }
}

int getValidatedInt()
{
    int value;
    while (true)
    {
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n' || value <= 0)
        {
            std::cout << "Invalid input. Please enter a valid positive and non-zero number.\n";
            std::cin.clear();
            flushInputBuffer();
        }
        else
        {
            flushInputBuffer();
            return value;
        }
    }
}
