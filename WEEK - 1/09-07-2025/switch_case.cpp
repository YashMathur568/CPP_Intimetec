#include <iostream>

void test(int x)
{
    switch (x)
    {
    case 1:
        std::cout << "One\n";
        break;
    case 2:
        std::cout << "Two\n";
        break;
    case 3:
        std::cout << "Three\n";
        break;
    case 4:
        std::cout << "Four\n";
        break;
    case 5:
        std::cout << "Five\n";
        break;
    default:
        std::cout << "Other\n";
        break;
    }
}
int main()
{
    for (int i = 0; i <= 6; ++i)
    {
        test(i);
    }
    return 0;
}
