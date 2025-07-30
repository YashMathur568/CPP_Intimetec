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
    int rows1, cols1, rows2, cols2;

    while (true)
    {
        getDimensionsFromUser("Matrix1", rows1, cols1);
        getDimensionsFromUser("Matrix2", rows2, cols2);

        if (rows1 == rows2 && cols1 == cols2)
            break;

        std::cout << "For addition, both matrices must have the same dimensions.\n";
    }

    MatrixInfo matrix1 = getMatrixFromUser("Matrix1", rows1, cols1);
    MatrixInfo matrix2 = getMatrixFromUser("Matrix2", rows2, cols2);

    MatrixInfo result = addMatrices(matrix1, matrix2);
    displayMatrix(result, result.name);

    deleteMatrix(matrix1);
    deleteMatrix(matrix2);
    deleteMatrix(result);
}

void performMultiplication()
{
    int rows1, cols1, rows2, cols2;

    while (true)
    {
        getDimensionsFromUser("Matrix1", rows1, cols1);
        getDimensionsFromUser("Matrix2", rows2, cols2);

        if (cols1 == rows2)
            break;

        std::cout << "For multiplication, columns of Matrix1 must equal rows of Matrix2.\n";
    }

    MatrixInfo matrix1 = getMatrixFromUser("Matrix1", rows1, cols1);
    MatrixInfo matrix2 = getMatrixFromUser("Matrix2", rows2, cols2);

    MatrixInfo result = multiplyMatrices(matrix1, matrix2);
    displayMatrix(result, result.name);

    deleteMatrix(matrix1);
    deleteMatrix(matrix2);
    deleteMatrix(result);
}

int main()
{
    while (true)
    {
        std::cout << "\nMatrix Operations Menu:\n";
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
