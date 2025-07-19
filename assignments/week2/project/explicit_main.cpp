#include <iostream>
#include <dlfcn.h>
#include <stdexcept>

struct OperationContext
{
    double operand1;
    double operand2;
    int choice;
    void *handle;
};

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

bool executeOperation(const OperationContext &oc, const char *funcName, char symbol)
{
    double (*operation)(double, double) = (double (*)(double, double))dlsym(oc.handle, funcName);
    if (!operation)
    {
        std::cout << "Error: Could not find '" << funcName << "' function in library." << std::endl;
        return false;
    }

    try
    {
        double result = operation(oc.operand1, oc.operand2);
        std::cout << oc.operand1 << " " << symbol << " " << oc.operand2 << " = " << result << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return false;
    }

    return true;
}

int performOperation(const OperationContext &oc)
{
    switch (oc.choice)
    {
    case 1:
        return executeOperation(oc, "add", '+') ? 0 : 1;
    case 2:
        return executeOperation(oc, "subtract", '-') ? 0 : 1;
    case 3:
        return executeOperation(oc, "multiply", '*') ? 0 : 1;
    case 4:
        return executeOperation(oc, "divide", '/') ? 0 : 1;
    default:
        std::cout << "Invalid choice! Please enter from 1 to 4." << std::endl;
        return 1;
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

    void *handle = dlopen("./l/ib/libmathops.so", RTLD_LAZY);
    if (!handle)
    {
        std::cout << "Cannot open library: " << dlerror() << std::endl;
        return 1;
    }

    OperationContext oc = {operand1, operand2, choice, handle};

    int status = performOperation(oc);

    dlclose(handle);
    return status;
}
