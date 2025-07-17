#include <iostream>
#include <dlfcn.h>
#include <stdexcept>

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

    void *handle = dlopen("lib/libmathops.so", RTLD_LAZY);
    if (!handle)
    {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        return 1;
    }

    dlerror();

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
            dlclose(handle);
            return 1;
        }

        break;
    }
    default:
        std::cerr << "Invalid choice!Please enter from 1 to 4." << std::endl;
        dlclose(handle);
        return 1;
    }

    dlclose(handle);
    return 0;
}