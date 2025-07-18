#include <iostream>

void printRow(int ColNum)
{
    std::cout << (ColNum % 2 == 0 ? "1 " : "0 ");
}

void printLeftHalf(int row, int Totalrows)
{
    for (int column = 0; column <= row; column++)
    {
        if (column != Totalrows / 2)
        {
            printRow(column);
        }
    }
}

void printRightHalf(int row)
{
    for (int column = 0; column <= row; column++)
    {
        printRow(column);
    }
}

void printSpaces(int count)
{
    for (int space = 0; space < count; space++)
    {
        std::cout << "  ";
    }
}

void printUpperHalf(int Totalrows)
{
    for (int row = 0; row <= Totalrows / 2; row++)
    {
        printLeftHalf(row, Totalrows);
        printSpaces(Totalrows - (2 * row) - 2);
        printRightHalf(row);
        std::cout << std::endl;
    }
}

void printLowerHalf(int Totalrows)
{
    for (int row = 0; row < Totalrows / 2; row++)
    {
        int limit = (Totalrows / 2) - row;
        for (int column = 0; column < limit; column++)
        {
            printRow(column);
        }

        printSpaces(2 * row + 1);

        for (int column = 0; column < limit; column++)
        {
            printRow(column);
        }
        std::cout << std::endl;
    }
}

void makePattern(int Totalrows)
{
    printUpperHalf(Totalrows);
    printLowerHalf(Totalrows);
}

int main()
{
    int size;
    while (true)
    {
        std::cout << "Enter the size of the pattern (positive integer): ";
        std::cin >> size;

        if (std::cin.fail() || size <= 0)
        {
            std::cout << "Invalid input. Please enter a positive number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else
        {
            break;
        }
    }

    size = 2 * size + 1;
    makePattern(size);
    return 0;
}
