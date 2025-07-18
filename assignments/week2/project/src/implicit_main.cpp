#include <iostream>
#include <stdexcept>
#include "../include/math_operations.h"

double getValidatedOperand(int operandNumber)
{
    double value;
    while (true)
    {
        std::cout << "Enter Value of Operand " << operandNumber << " : ";
        std::cin >> value;

        if (!std::cin.fail())
            break;

        std::cout << "Invalid input. Please enter a number.\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    return value;
}

int getValidatedChoice()
{
    int choice;
    while (true)
    {
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        if (!std::cin.fail())
            break;

        std::cout << "Invalid input. Please enter a number.\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    return choice;
}

void performOperation(int choice, double operand1, double operand2)
{
    switch (choice)
    {
    case 1:
        std::cout << operand1 << " + " << operand2 << " = " << add(operand1, operand2) << "\n";
        break;
    case 2:
        std::cout << operand1 << " - " << operand2 << " = " << subtract(operand1, operand2) << "\n";
        break;
    case 3:
        std::cout << operand1 << " * " << operand2 << " = " << multiply(operand1, operand2) << "\n";
        break;
    case 4:
        try
        {
            std::cout << operand1 << " / " << operand2 << " = " << divide(operand1, operand2) << "\n";
        }
        catch (const std::runtime_error &e)
        {
            std::cout << "Error: " << e.what() << "\n";
        }
        break;
    default:
        std::cout << "Invalid choice! Please enter from 1 to 4.\n";
    }
}

int main()
{
    double operand1 = getValidatedOperand(1);
    double operand2 = getValidatedOperand(2);

    std::cout << "Enter the type of arithmetic operation you want to perform:\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)\n";

    int choice = getValidatedChoice();

    performOperation(choice, operand1, operand2);

    return 0;
}
