#include <iostream>
#include <stdexcept>
#include "math_operations.h"

int main()
{
    double operand1, operand2;
    int choice;

    std::cout << "Enter value of operand 1: ";
    std::cin >> operand1;
    std::cout << "Enter value of operand 2: ";
    std::cin >> operand2;

    std::cout << "Enter the type of arithmetic operation you want to perform:" << std::endl;
    std::cout << "1. Addition (+)" << std::endl;
    std::cout << "2. Subtraction (-)" << std::endl;
    std::cout << "3. Multiplication (*)" << std::endl;
    std::cout << "4. Division (/)" << std::endl;
    std::cout << "Enter your choice (1-4): ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << operand1 << " + " << operand2 << " = " << add(operand1, operand2) << std::endl;
        break;
    case 2:
        std::cout << operand1 << " - " << operand2 << " = " << subtract(operand1, operand2) << std::endl;
        break;
    case 3:
        std::cout << operand1 << " * " << operand2 << " = " << multiply(operand1, operand2) << std::endl;
        break;
    case 4:
        try
        {
            std::cout << operand1 << " / " << operand2 << " = " << divide(operand1, operand2) << std::endl;
        }
        catch (const std::runtime_error &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
        break;
    default:
        std::cout << "Invalid choice!Please enter from 1 to 4." << std::endl;
    }

    return 0;
}