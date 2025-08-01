#ifndef MATRIX_H
#define MATRIX_H

#include <string>

class Matrix
{
private:
    int totalRows;
    int totalColumns;
    double **matrix;
    std::string name;

    void allocateMatrix();
    void deallocateMatrix();

public:
    Matrix(int row, int column, const std::string &name);
    ~Matrix();

    int getMatrixRows();
    int getMatrixColumns();
    std::string &getMatrixName();
    double **getMatrixPointer();

    Matrix operator+(Matrix &other);
    Matrix operator*(Matrix &other);
};

#endif
