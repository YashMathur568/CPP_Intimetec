#include <iostream>
#include "matrix.h"
#include "input_output_utils.h"

enum MenuOption
{
    ADDITION = 1,
    MULTIPLICATION,
    EXIT
};

void handleMatrixAddition()
{
    int rows1, cols1, rows2, cols2;

    while (true)
    {
        getMatrixDimensions("Matrix A", rows1, cols1);
        getMatrixDimensions("Matrix B", rows2, cols2);

        if (rows1 == rows2 && cols1 == cols2)
            break;

        std::cout << "Dimensions mismatch. Both matrices must be of the same size.\n";
    }

    Matrix matrixA(rows1, cols1, "Matrix A");
    inputMatrixValues(matrixA);

    Matrix matrixB(rows2, cols2, "Matrix B");
    inputMatrixValues(matrixB);

    Matrix result = matrixA + matrixB;
    displayMatrix(result);
}

void handleMatrixMultiplication()
{
    int rows1, cols1, rows2, cols2;

    while (true)
    {
        getMatrixDimensions("Matrix A", rows1, cols1);
        getMatrixDimensions("Matrix B", rows2, cols2);

        if (cols1 == rows2)
            break;

        std::cout << "Invalid. Columns of Matrix A must be equal to rows of Matrix B.\n";
    }

    Matrix matrixA(rows1, cols1, "Matrix A");
    inputMatrixValues(matrixA);

    Matrix matrixB(rows2, cols2, "Matrix B");
    inputMatrixValues(matrixB);

    Matrix result = matrixA * matrixB;
    displayMatrix(result);
}

int main()
{
    while (true)
    {
        std::cout << "\nMatrix Operations Menu:\n";
        std::cout << "1. Matrix Addition\n";
        std::cout << "2. Matrix Multiplication\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option from 1 to 3: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cout << "Invalid input.\n";
            std::cin.clear();
            flushInputBuffer();
        }
        else
        {
            switch (choice)
            {
            case ADDITION:
                handleMatrixAddition();
                break;
            case MULTIPLICATION:
                handleMatrixMultiplication();
                break;
            case EXIT:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice.\n";
            }
        }
    }
}
