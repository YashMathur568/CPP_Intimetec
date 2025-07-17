#include <iostream>
#include <dlfcn.h>
#include <stdexcept>

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

int performOperation(int choice, double operand1, double operand2, void *handle)
{
    double result;

    switch (choice)
    {
    case 1:
    {
        double (*add_func)(double, double) = (double (*)(double, double))dlsym(handle, "add");
        result = add_func(operand1, operand2);
        std::cout << operand1 << " + " << operand2 << " = " << result << std::endl;
        break;
    }
    case 2:
    {
        double (*subtract_func)(double, double) = (double (*)(double, double))dlsym(handle, "subtract");
        result = subtract_func(operand1, operand2);
        std::cout << operand1 << " - " << operand2 << " = " << result << std::endl;
        break;
    }
    case 3:
    {
        double (*multiply_func)(double, double) = (double (*)(double, double))dlsym(handle, "multiply");
        result = multiply_func(operand1, operand2);
        std::cout << operand1 << " * " << operand2 << " = " << result << std::endl;
        break;
    }
    case 4:
    {
        double (*divide_func)(double, double) = (double (*)(double, double))dlsym(handle, "divide");
        try
        {
            result = divide_func(operand1, operand2);
            std::cout << operand1 << " / " << operand2 << " = " << result << std::endl;
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << "Error: " << e.what();
            return 1;
        }

        break;
    }
    default:
        std::cerr << "Invalid choice!Please enter from 1 to 4." << std::endl;
        return 1;
    }

    return 0;
}

int main()
{
    double operand1 = getValidatedOperand(1);
    double operand2 = getValidatedOperand(2);

    std::cout << "Enter the type of arithmetic operation you want to perform:" << std::endl;
    std::cout << "1. Addition (+)" << std::endl;
    std::cout << "2. Subtraction (-)" << std::endl;
    std::cout << "3. Multiplication (*)" << std::endl;
    std::cout << "4. Division (/)" << std::endl;
    std::cout << "Enter your choice (1-4): ";
    int choice = getValidatedChoice();

    void *handle = dlopen("../lib/libmathops.so", RTLD_LAZY);
    if (!handle)
    {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        return 1;
    }

    dlerror();

    int status = performOperation(choice, operand1, operand2, handle);

    dlclose(handle);
    return status;
}
