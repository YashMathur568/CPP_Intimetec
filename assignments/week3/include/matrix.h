#ifndef MATRIX_H
#define MATRIX_H
#include <string>

struct MatrixInfo
{
    int totalRows = 0;
    int totalCols = 0;
    double **matrix = nullptr;
};

void allocateMatrix(MatrixInfo &matInfo);
void flushInputBuffer();
int getValidatedInput(const std::string &prompt);
MatrixInfo getMatrix(const std::string &name);
void deleteMatrix(MatrixInfo &matInfo);
void inputMatrix(MatrixInfo &matInfo, const std::string &name);
void displayMatrix(MatrixInfo &matInfo, const std::string &name);
MatrixInfo addMatrices(MatrixInfo &matrix1, MatrixInfo &matrix2);
MatrixInfo multiplyMatrices(MatrixInfo &matrix1, MatrixInfo &matrix2);

#endif
