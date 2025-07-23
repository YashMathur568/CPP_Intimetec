#include "matrix.h"
#include <iostream>
#include <string>

void allocateMatrix(MatrixInfo &m)
{
    m.matrix = new double *[m.totalRows];
    for (int i = 0; i < m.totalRows; i++)
    {
        m.matrix[i] = new double[m.totalCols];
    }
}

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

MatrixInfo getMatrix(const std::string &name)
{
    MatrixInfo m;
    std::string rowPrompt = "Enter number of rows for Matrix " + name + ": ";
    std::string colPrompt = "Enter number of columns for Matrix " + name + ": ";
    m.totalRows = getValidatedInput(rowPrompt);
    m.totalCols = getValidatedInput(colPrompt);
    allocateMatrix(m);
    return m;
}

void deleteMatrix(MatrixInfo &m)
{
    for (int i = 0; i < m.totalRows; i++)
    {
        delete[] m.matrix[i];
    }
    delete[] m.matrix;
    m.matrix = nullptr;
}

void inputMatrix(MatrixInfo &m, const std::string &name)
{
    std::cout << "Enter values for matrix " << name << ":\n";
    for (int row = 0; row < m.totalRows; row++)
    {
        for (int col = 0; col < m.totalCols; col++)
        {
            while (true)
            {
                std::cout << name << "[" << row << "][" << col << "] = ";
                std::cin >> m.matrix[row][col];

                if (std::cin.fail() || std::cin.peek() != '\n')
                {
                    std::cout << "Invalid input. Please enter a valid number." << std::endl;
                    std::cin.clear();
                    flushInputBuffer();
                }
                else
                {
                    flushInputBuffer();
                    break;
                }
            }
        }
    }
}

void displayMatrix(MatrixInfo &m, const std::string &name)
{
    std::cout << "\nMatrix " << name << ":\n";
    for (int row = 0; row < m.totalRows; row++)
    {
        for (int col = 0; col < m.totalCols; col++)
        {
            std::cout << m.matrix[row][col] << " ";
        }
        std::cout << "\n";
    }
}

MatrixInfo addMatrices(MatrixInfo &A, MatrixInfo &B)
{
    MatrixInfo result;
    result.totalRows = A.totalRows;
    result.totalCols = A.totalCols;
    allocateMatrix(result);

    for (int row = 0; row < result.totalRows; row++)
    {
        for (int col = 0; col < result.totalCols; col++)
        {
            result.matrix[row][col] = A.matrix[row][col] + B.matrix[row][col];
        }
    }

    return result;
}

MatrixInfo multiplyMatrices(MatrixInfo &A, MatrixInfo &B)
{
    MatrixInfo result;
    result.totalRows = A.totalRows;
    result.totalCols = B.totalCols;
    allocateMatrix(result);

    for (int row = 0; row < result.totalRows; row++)
    {
        for (int col = 0; col < result.totalCols; col++)
        {
            result.matrix[row][col] = 0;
            for (int k = 0; k < A.totalCols; k++)
            {
                result.matrix[row][col] += A.matrix[row][k] * B.matrix[k][col];
            }
        }
    }

    return result;
}