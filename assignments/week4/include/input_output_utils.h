#ifndef INPUT_OUTPUT_UTILS_H
#define INPUT_OUTPUT_UTILS_H

#include <string>
class Matrix;

void flushInputBuffer();
int getValidatedInput(const std::string &prompt);
void getMatrixDimensions(const std::string &matrixName, int &rows, int &columns);

void inputMatrixValues(Matrix &matrix, const std::string &matrixName);
void displayMatrix(Matrix &matrix, const std::string &matrixName);

#endif
