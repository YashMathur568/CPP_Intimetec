#include <iostream>

int add(int a, int b);

int main()
{
    int a = 2;
    int b = 3;
    int c = add(a, b);
    std::cout << c << std::endl;
    return 0;
}