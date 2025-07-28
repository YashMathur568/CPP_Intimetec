#include "matrix.h"
#include "input_utils.h"
#include <iostream>
#include <string>

void allocateMatrix(MatrixInfo &matInfo)
{
    matInfo.matrix = new double *[matInfo.totalRows];
    for (int i = 0; i < matInfo.totalRows; i++)
    {
        matInfo.matrix[i] = new double[matInfo.totalCols];
    }
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
    result.name = matrix1.name + " + " + matrix2.name;
    allocateMatrix(result);

    for (int row = 0; row < result.totalRows; row++)
    {
        for (int col = 0; col < result.totalCols; col++)
        {
            *(result.matrix[row] + col) = *(matrix1.matrix[row] + col) + *(matrix2.matrix[row] + col);
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
            for (int innerDim = 0; innerDim < matrix1.totalCols; innerDim++)
            {
                *(result.matrix[row] + col) += *(matrix1.matrix[row] + innerDim) * *(matrix2.matrix[innerDim] + col);
            }
        }
    }
    return result;
}

MatrixInfo initializeMatrix(const std::string &name)
{
    MatrixInfo matInfo;
    matInfo.name = name;
    getDimensionsFromUser(name, matInfo.totalRows, matInfo.totalCols);
    allocateMatrix(matInfo);
    return matInfo;
}
