#include <iostream>

int globalVar = 10;

void checkStatic()
{
    static int count = 4;
    count++;
    std::cout << "Static count: " << count << "\n";
}

int main()
{
    int localVar = 50;
    std::cout << "Global Var: " << globalVar << "\n";
    std::cout << "Local Var: " << localVar << "\n";

    checkStatic();
    checkStatic();
    checkStatic();
}
