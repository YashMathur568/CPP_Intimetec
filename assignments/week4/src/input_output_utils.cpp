#include "input_output_utils.h"
#include "matrix.h"
#include <iostream>

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

void getMatrixDimensions(const std::string &matrixName, int &rows, int &columns)
{
    rows = getValidatedInput("Enter number of rows for " + matrixName + ": ");
    columns = getValidatedInput("Enter number of columns for " + matrixName + ": ");
}

void inputMatrixValues(Matrix &matrix, const std::string &matrixName)
{
    std::cout << "Enter values for " << matrixName << ":\n";
    for (int row = 0; row < matrix.getMatrixRows(); row++)
    {
        for (int column = 0; column < matrix.getMatrixColumns(); column++)
        {
            while (true)
            {
                std::cout << matrixName << "[" << row << "][" << column << "] = ";
                std::cin >> *(*(matrix.getMatrixPointer() + row) + column);
                if (std::cin.fail() || std::cin.peek() != '\n')
                {
                    std::cout << "Invalid input. Try again.\n";
                    std::cin.clear();
                    flushInputBuffer();
                }
                else
                    break;
            }
        }
    }
}

void displayMatrix(Matrix &matrix, const std::string &matrixName)
{
    std::cout << matrixName << ":\n";
    for (int row = 0; row < matrix.getMatrixRows(); row++)
    {
        for (int column = 0; column < matrix.getMatrixColumns(); column++)
        {
            std::cout << *(*(matrix.getMatrixPointer() + row) + column) << " ";
        }
        std::cout << "\n";
    }
}
