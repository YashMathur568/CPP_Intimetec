#include "matrix.h"
#include "input_utils.h"
#include <iostream>
#include <string>

void allocateMatrix(MatrixInfo &matInfo)
{
    matInfo.matrix = new (std::nothrow) double *[matInfo.totalRows];
    if (matInfo.matrix == nullptr)
    {
        std::cerr << "Memory allocation failed for row pointers." << std::endl;
        std::exit(1);
    }
    for (int row = 0; row < matInfo.totalRows; row++)
    {
        matInfo.matrix[row] = new (std::nothrow) double[matInfo.totalCols];
        if (matInfo.matrix[row] == nullptr)
        {
            std::cerr << "Memory allocation failed for row " << row << std::endl;
            std::exit(1);
        }
    }
}

void deleteMatrix(MatrixInfo &matInfo)
{
    for (int row = 0; row < matInfo.totalRows; row++)
    {
        delete[] matInfo.matrix[row];
    }
    delete[] matInfo.matrix;
    matInfo.matrix = nullptr;
}

void populateMatrix(MatrixInfo &matInfo)
{
    std::cout << "Enter values for " << matInfo.name << ":\n";
    for (int row = 0; row < matInfo.totalRows; row++)
    {
        for (int col = 0; col < matInfo.totalCols; col++)
        {
            while (true)
            {
                std::cout << matInfo.name << "[" << row << "][" << col << "] = ";
                std::cin >> *(*(matInfo.matrix + row) + col);

                if (std::cin.fail() || std::cin.peek() != '\n')
                {
                    std::cout << "Invalid input. Please enter a valid number." << std::endl;
                    std::cin.clear();
                    flushInputBuffer();
                }
                else
                {
                    break;
                }
            }
        }
    }
}

void displayMatrix(MatrixInfo &matInfo, const std::string &name)
{
    std::cout << name << ":\n";
    for (int row = 0; row < matInfo.totalRows; row++)
    {
        for (int col = 0; col < matInfo.totalCols; col++)
        {
            std::cout << *(*(matInfo.matrix + row) + col) << " ";
        }
        std::cout << std::endl;
    }
}

MatrixInfo addMatrices(MatrixInfo &matrix1, MatrixInfo &matrix2)
{
    MatrixInfo result;
    result.totalRows = matrix1.totalRows;
    result.totalCols = matrix1.totalCols;
    result.name = matrix1.name + " + " + matrix2.name;
    allocateMatrix(result);

    for (int row = 0; row < result.totalRows; row++)
    {
        for (int col = 0; col < result.totalCols; col++)
        {
            *(*(result.matrix + row) + col) =
                *(*(matrix1.matrix + row) + col) + *(*(matrix2.matrix + row) + col);
        }
    }
    return result;
}

MatrixInfo multiplyMatrices(MatrixInfo &matrix1, MatrixInfo &matrix2)
{
    MatrixInfo result;
    result.totalRows = matrix1.totalRows;
    result.totalCols = matrix2.totalCols;
    result.name = matrix1.name + " * " + matrix2.name;
    allocateMatrix(result);

    for (int row = 0; row < result.totalRows; row++)
    {
        for (int col = 0; col < result.totalCols; col++)
        {
            *(result.matrix[row] + col) = 0;
            for (int inner = 0; inner < matrix1.totalCols; inner++)
            {
                *(*(result.matrix + row) + col) +=
                    *(*(matrix1.matrix + row) + inner) *
                    *(*(matrix2.matrix + inner) + col);
            }
        }
    }
    return result;
}

MatrixInfo getMatrixFromUser(const std::string &name, int rows, int cols)
{
    MatrixInfo matInfo;
    matInfo.name = name;
    matInfo.totalRows = rows;
    matInfo.totalCols = cols;
    allocateMatrix(matInfo);
    populateMatrix(matInfo);
    return matInfo;
}
