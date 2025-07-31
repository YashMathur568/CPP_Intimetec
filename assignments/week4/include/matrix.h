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

    void allocate();
    void deallocate();

public:
    Matrix(int r, int c, const std::string &n);
    ~Matrix();

    void input();
    void display();

    Matrix add(Matrix &other);
    Matrix multiply(Matrix &other);
};

#endif