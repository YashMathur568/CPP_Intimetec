#include <iostream>

int main()
{
    int rows = 2, cols = 3;
    int *matrix = new int[rows * cols];

    std::cout << "Enter values (Column-Major):\n";
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> matrix[j * rows + i];
        }
    }

    std::cout << "\nMatrix (Displayed in Row Format):\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[j * rows + i] << " ";
        }
        std::cout << "\n";
    }
    delete[] matrix;
}