#include <iostream>
#include "matrix.h"
#include "input_utils.h"

enum MenuOption
{
    ADDITION = 1,
    MULTIPLICATION,
    EXIT
};

void performAddition()
{
    MatrixInfo matrix1 = initializeMatrix("Matrix1");
    MatrixInfo matrix2 = initializeMatrix("Matrix2");

    while (matrix1.totalRows != matrix2.totalRows || matrix1.totalCols != matrix2.totalCols)
    {
        std::cout << "For addition both the matrices must have the same dimensions." << std::endl;
        deleteMatrix(matrix1);
        deleteMatrix(matrix2);
        matrix1 = initializeMatrix("Matrix1");
        matrix2 = initializeMatrix("Matrix2");
    }

    populateMatrix(matrix1);
    populateMatrix(matrix2);

    MatrixInfo result = addMatrices(matrix1, matrix2);
    displayMatrix(result, "Matrix1 + Matrix2");

    deleteMatrix(matrix1);
    deleteMatrix(matrix2);
    deleteMatrix(result);
}

void performMultiplication()
{
    MatrixInfo matrix1 = initializeMatrix("Matrix1");
    MatrixInfo matrix2 = initializeMatrix("Matrix2");

    while (matrix1.totalCols != matrix2.totalRows)
    {
        std::cout << "For multiplication, columns of Matrix 1 must equal rows of Matrix 2." << std::endl;
        deleteMatrix(matrix1);
        deleteMatrix(matrix2);
        matrix1 = initializeMatrix("Matrix1");
        matrix2 = initializeMatrix("Matrix2");
    }

    populateMatrix(matrix1);
    populateMatrix(matrix2);

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
        std::cout << "Matrix Operations Menu:\n";
        std::cout << "1. Matrix Addition\n";
        std::cout << "2. Matrix Multiplication\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option From 1 To 3: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cout << "Invalid input. Please enter a valid number from 1 to 3.\n";
            std::cin.clear();
            flushInputBuffer();
        }
        else
        {
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
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    }
}
