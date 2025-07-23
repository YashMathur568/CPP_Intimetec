#include <iostream>
#include "matrix.h"

void performAddition()
{
    MatrixInfo A = getMatrix("A");
    MatrixInfo B = getMatrix("B");

    while (A.totalRows != B.totalRows || A.totalCols != B.totalCols)
    {
        std::cout << "For addition both the matrices must have the same dimensions." << std::endl;
        deleteMatrix(A);
        deleteMatrix(B);
        A = getMatrix("A");
        B = getMatrix("B");
    }

    inputMatrix(A, "A");
    inputMatrix(B, "B");

    MatrixInfo result = addMatrices(A, B);
    displayMatrix(result, "A + B");

    deleteMatrix(A);
    deleteMatrix(B);
    deleteMatrix(result);
}

void performMultiplication()
{
    MatrixInfo A = getMatrix("A");
    MatrixInfo B = getMatrix("B");

    while (A.totalCols != B.totalRows)
    {
        std::cout << "For multiplication, columns of Matrix A must equal rows of Matrix B." << std::endl;
        deleteMatrix(A);
        deleteMatrix(B);
        A = getMatrix("A");
        B = getMatrix("B");
    }

    inputMatrix(A, "A");
    inputMatrix(B, "B");

    MatrixInfo result = multiplyMatrices(A, B);
    displayMatrix(result, "A * B");

    deleteMatrix(A);
    deleteMatrix(B);
    deleteMatrix(result);
}

int main()
{
    while (true)
    {
        std::cout << "\nMatrix Operations Menu:" << std::endl;
        std::cout << "2. Matrix Multiplication" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Choose an option From 1 To 3: ";

        int choice;
        std::cin >> choice;
        flushInputBuffer();

        switch (choice)
        {
        case 1:
            performAddition();
            break;
        case 2:
            performMultiplication();
            break;
        case 3:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid choice.Please try again." << std::endl;
        }
    }
}
