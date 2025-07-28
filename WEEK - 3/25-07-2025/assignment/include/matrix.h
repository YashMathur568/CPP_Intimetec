#ifndef MATRIX_H
#define MATRIX_H
#include <string>

struct MatrixInfo
{
    int totalRows = 0;
    int totalCols = 0;
    double **matrix = nullptr;
    std::string name;
};

void allocateMatrix(MatrixInfo &matInfo);
void deleteMatrix(MatrixInfo &matInfo);
void populateMatrix(MatrixInfo &matInfo);
void displayMatrix(MatrixInfo &matInfo, const std::string &name);
MatrixInfo addMatrices(MatrixInfo &matrix1, MatrixInfo &matrix2);
MatrixInfo multiplyMatrices(MatrixInfo &matrix1, MatrixInfo &matrix2);
MatrixInfo initializeMatrix(const std::string &name);

#endif
