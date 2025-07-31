#include <iostream>
#include <string>
#include "input_utils.h"

void flushInputBuffer()
{
    while (getchar() != '\n')
        ;
}

int getValidatedInput(const std::string &prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n' || value <= 0)
        {
            std::cout << "Please enter a valid positive and non-zero number.\n";
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

void getDimensionsFromUser(const std::string &name, int &rows, int &cols)
{
    rows = getValidatedInput("Enter number of rows for " + name + ": ");
    cols = getValidatedInput("Enter number of columns for " + name + ": ");
}