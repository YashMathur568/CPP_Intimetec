#include <iostream>
#include "matrix.h"

enum MenuOption
{
    ADDITION = 1,
    MULTIPLICATION,
    EXIT
};

void performAddition()
{
    MatrixInfo matrix1 = getMatrix("Matrix1");
    MatrixInfo matrix2 = getMatrix("Matrix2");

    while (matrix1.totalRows != matrix2.totalRows || matrix1.totalCols != matrix2.totalCols)
    {
        std::cout << "For addition both the matrices must have the same dimensions." << std::endl;
        deleteMatrix(matrix1);
        deleteMatrix(matrix2);
        matrix1 = getMatrix("Matrix1");
        matrix2 = getMatrix("Matrix2");
    }

    inputMatrix(matrix1, "Matrix1");
    inputMatrix(matrix2, "Matrix2");

    MatrixInfo result = addMatrices(matrix1, matrix2);
    displayMatrix(result, "Matrix1 + Matrix2");

    deleteMatrix(matrix1);
    deleteMatrix(matrix2);
    deleteMatrix(result);
}

void performMultiplication()
{
    MatrixInfo matrix1 = getMatrix("Matrix1");
    MatrixInfo matrix2 = getMatrix("Matrix2");

    while (matrix1.totalCols != matrix2.totalRows)
    {
        std::cout << "For multiplication, columns of Matrix 1 must equal rows of Matrix 2." << std::endl;
        deleteMatrix(matrix1);
        deleteMatrix(matrix2);
        matrix1 = getMatrix("Matrix1");
        matrix2 = getMatrix("Matrix2");
    }

    inputMatrix(matrix1, "Matrix1");
    inputMatrix(matrix2, "Matrix2");

    MatrixInfo result = multiplyMatrices(matrix1, matrix2);
    displayMatrix(result, "Matrix1 * Matrix2");

    deleteMatrix(matrix1);
    deleteMatrix(matrix2);
    deleteMatrix(result);
}

int main()
{
    while (true)
    {
        std::cout << "\nMatrix Operations Menu:" << std::endl;
        std::cout << "1. Matrix Addition" << std::endl;
        std::cout << "2. Matrix Multiplication" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Choose an option From 1 To 3: ";

        int choice;
        std::cin >> choice;
        flushInputBuffer();

        switch (choice)
        {
        case ADDITION:
            performAddition();
            break;
        case MULTIPLICATION:
            performMultiplication();
            break;
        case EXIT:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}
