#include "matrix.h"
#include "input_utils.h"
#include <iostream>

Matrix::Matrix(int row, int col, const std::string &name)
    : totalRows(row), totalColumns(col), name(name)
{
    allocate();
}

Matrix::~Matrix()
{
    deallocate();
}

void Matrix::allocate()
{
    matrix = new double *[totalRows];
    for (int row = 0; row < totalRows; ++row)
        *(matrix + row) = new double[totalColumns];
}

void Matrix::deallocate()
{
    for (int row = 0; row < totalRows; ++row)
        delete[] *(matrix + row);
    delete[] matrix;
}

void Matrix::input()
{
    std::cout << "Enter values for " << name << ":\n";
    for (int row = 0; row < totalRows; ++row)
    {
        for (int col = 0; col < totalColumns; ++col)
        {
            while (true)
            {
                std::cout << name << "[" << row << "][" << col << "] = ";
                std::cin >> *(*(matrix + row) + col);
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

void Matrix::display()
{
    std::cout << name << ":\n";
    for (int row = 0; row < totalRows; ++row)
    {
        for (int col = 0; col < totalColumns; ++col)
        {
            std::cout << *(*(matrix + row) + col) << " ";
        }
        std::cout << "\n";
    }
}

Matrix Matrix::add(Matrix &other)
{
    Matrix result(totalRows, totalColumns, name + " + " + other.name);
    for (int row = 0; row < totalRows; ++row)
    {
        for (int col = 0; col < totalColumns; ++col)
        {
            *(*(result.matrix + row) + col) = *(*(matrix + row) + col) + *(*(other.matrix + row) + col);
        }
    }
    return result;
}

Matrix Matrix::multiply(Matrix &other)
{
    Matrix result(totalRows, other.totalColumns, name + " * " + other.name);
    for (int row = 0; row < totalRows; ++row)
    {
        for (int col = 0; col < other.totalColumns; ++col)
        {
            *(*(result.matrix + row) + col) = 0;
            for (int inner = 0; inner < totalColumns; ++inner)
            {
                *(*(result.matrix + row) + col) += *(*(matrix + row) + inner) * *(*(other.matrix + inner) + col);
            }
        }
    }
    return result;
}