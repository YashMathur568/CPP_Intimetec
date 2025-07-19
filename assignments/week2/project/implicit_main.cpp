#include <iostream>
#include <stdexcept>
#include "addition.h"
#include "division.h"
#include "multiplication.h"
#include "subtraction.h"

struct OperationContext
{
    double operand1;
    double operand2;
    int choice;
};

double getValidatedInput(const std::string &prompt)
{
    double value;
    while (true)
    {
        std::cout << prompt;
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

void executeOperation(const OperationContext &oc)
{
    try
    {
        switch (oc.choice)
        {
        case 1:
            std::cout << oc.operand1 << " + " << oc.operand2 << " = " << add(oc.operand1, oc.operand2) << "\n";
            break;
        case 2:
            std::cout << oc.operand1 << " - " << oc.operand2 << " = " << subtract(oc.operand1, oc.operand2) << "\n";
            break;
        case 3:
            std::cout << oc.operand1 << " * " << oc.operand2 << " = " << multiply(oc.operand1, oc.operand2) << "\n";
            break;
        case 4:
            std::cout << oc.operand1 << " / " << oc.operand2 << " = " << divide(oc.operand1, oc.operand2) << "\n";
            break;
        default:
            std::cout << "Invalid choice! Please enter from 1 to 4.\n";
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }
}

int main()
{
    double operand1 = getValidatedInput("Enter Value of Operand 1 : ");
    double operand2 = getValidatedInput("Enter Value of Operand 2 : ");

    std::cout << "Enter the type of arithmetic operation you want to perform:\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)\n";

    int choice = getValidatedChoice();

    OperationContext oc = {operand1, operand2, choice};
    executeOperation(oc);

    return 0;
}
