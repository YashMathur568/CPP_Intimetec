#include "matrix.h"
#include <iostream>
#include <string>

void allocateMatrix(MatrixInfo &matInfo)
{
    try
    {
        matInfo.matrix = new double *[matInfo.totalRows];
        for (int i = 0; i < matInfo.totalRows; i++)
        {
            matInfo.matrix[i] = new double[matInfo.totalCols];
        }
    }
    catch (const std::bad_alloc &e)
    {
        std::cout << "Memory allocation failed: " << std::endl;
        std::exit(1);
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
    MatrixInfo matInfo;
    std::string rowPrompt = "Enter number of rows for " + name + " : ";
    std::string colPrompt = "Enter number of columns for " + name + " : ";
    matInfo.totalRows = getValidatedInput(rowPrompt);
    matInfo.totalCols = getValidatedInput(colPrompt);
    allocateMatrix(matInfo);
    return matInfo;
}

void deleteMatrix(MatrixInfo &matInfo)
{
    for (int i = 0; i < matInfo.totalRows; i++)
    {
        delete[] matInfo.matrix[i];
    }
    delete[] matInfo.matrix;
    matInfo.matrix = nullptr;
}

void inputMatrix(MatrixInfo &matInfo, const std::string &name)
{
    std::cout << "Enter values for " << name << ":\n";
    for (int row = 0; row < matInfo.totalRows; row++)
    {
        for (int col = 0; col < matInfo.totalCols; col++)
        {
            while (true)
            {
                std::cout << name << "[" << row << "][" << col << "] = ";
                std::cin >> matInfo.matrix[row][col];

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

void displayMatrix(MatrixInfo &matInfo, const std::string &name)
{
    std::cout << name << ":" << std::endl;
    for (int row = 0; row < matInfo.totalRows; row++)
    {
        for (int col = 0; col < matInfo.totalCols; col++)
        {
            std::cout << matInfo.matrix[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

MatrixInfo addMatrices(MatrixInfo &matrix1, MatrixInfo &matrix2)
{
    MatrixInfo result;
    result.totalRows = matrix1.totalRows;
    result.totalCols = matrix1.totalCols;
    allocateMatrix(result);

    for (int row = 0; row < result.totalRows; row++)
    {
        for (int col = 0; col < result.totalCols; col++)
        {
            result.matrix[row][col] = matrix1.matrix[row][col] + matrix2.matrix[row][col];
        }
    }

    return result;
}

MatrixInfo multiplyMatrices(MatrixInfo &matrix1, MatrixInfo &matrix2)
{
    MatrixInfo result;
    result.totalRows = matrix1.totalRows;
    result.totalCols = matrix2.totalCols;
    allocateMatrix(result);

    for (int row = 0; row < result.totalRows; row++)
    {
        for (int col = 0; col < result.totalCols; col++)
        {
            result.matrix[row][col] = 0;
            for (int innerDim = 0; innerDim < matrix1.totalCols; innerDim++)
            {
                result.matrix[row][col] += matrix1.matrix[row][innerDim] * matrix2.matrix[innerDim][col];
            }
        }
    }

    return result;
}
