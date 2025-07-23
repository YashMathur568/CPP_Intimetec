#ifndef MATRIX_H
#define MATRIX_H
#include <string>

struct MatrixInfo
{
    int totalRows = 0;
    int totalCols = 0;
    double **matrix = nullptr;
};

void allocateMatrix(MatrixInfo &m);
void flushInputBuffer();
int getValidatedInput(const std::string &prompt);
MatrixInfo getMatrix(const std::string &name);
void deleteMatrix(MatrixInfo &m);
void inputMatrix(MatrixInfo &m, const std::string &name);
void displayMatrix(MatrixInfo &m, const std::string &name);
MatrixInfo addMatrices(MatrixInfo &A, MatrixInfo &B);
MatrixInfo multiplyMatrices(MatrixInfo &A, MatrixInfo &B);

#endif