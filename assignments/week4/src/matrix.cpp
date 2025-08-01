#include "matrix.h"

Matrix::Matrix(int row, int column, const std::string &name)
    : totalRows(row), totalColumns(column), name(name)
{
    allocateMatrix();
}

Matrix::~Matrix()
{
    deallocateMatrix();
}

void Matrix::allocateMatrix()
{
    matrix = new double *[totalRows];
    for (int row = 0; row < totalRows; row++)
        *(matrix + row) = new double[totalColumns];
}

void Matrix::deallocateMatrix()
{
    for (int row = 0; row < totalRows; row++)
        delete[] *(matrix + row);
    delete[] matrix;
}

int Matrix::getMatrixRows() { return totalRows; }
int Matrix::getMatrixColumns() { return totalColumns; }
std::string &Matrix::getMatrixName() { return name; }
double **Matrix::getMatrixPointer() { return matrix; }

Matrix Matrix::operator+(Matrix &other)
{
    Matrix result(totalRows, totalColumns, name + " + " + other.name);
    for (int row = 0; row < totalRows; row++)
    {
        for (int column = 0; column < totalColumns; column++)
        {
            *(*(result.matrix + row) + column) = *(*(matrix + row) + column) + *(*(other.matrix + row) + column);
        }
    }
    return result;
}

Matrix Matrix::operator*(Matrix &other)
{
    Matrix result(totalRows, other.totalColumns, name + " * " + other.name);
    for (int row = 0; row < totalRows; row++)
    {
        for (int column = 0; column < other.totalColumns; column++)
        {
            *(*(result.matrix + row) + column) = 0;
            for (int inner = 0; inner < totalColumns; inner++)
            {
                *(*(result.matrix + row) + column) += *(*(matrix + row) + inner) * *(*(other.matrix + inner) + column);
            }
        }
    }
    return result;
}
