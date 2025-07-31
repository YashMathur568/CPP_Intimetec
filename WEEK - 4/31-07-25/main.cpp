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

        std::cout << "Dimensions mismatch. Both matrices must be of same size.\n";
    }

    Matrix m1(rows1, cols1, "Matrix1");
    m1.input();

    Matrix m2(rows2, cols2, "Matrix2");
    m2.input();

    Matrix result = m1.add(m2);
    result.display();
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

        std::cout << "Invalid. Columns of Matrix1 must equal rows of Matrix2.\n";
    }

    Matrix m1(rows1, cols1, "Matrix1");
    m1.input();

    Matrix m2(rows2, cols2, "Matrix2");
    m2.input();

    Matrix result = m1.multiply(m2);
    result.display();
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
            std::cout << "Invalid input.\n";
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
                std::cout << "Invalid choice.\n";
            }
        }
    }
}
