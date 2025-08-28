#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
    int totalRows;
    int totalColumns;
    double **matrix;

    void allocateMatrix();
    void deallocateMatrix();

public:
    Matrix(int row, int column);
    ~Matrix();

    int getMatrixRows();
    int getMatrixColumns();
    double **getMatrixPointer();

    Matrix operator+(Matrix &other);
    Matrix operator*(Matrix &other);
};

#endif
