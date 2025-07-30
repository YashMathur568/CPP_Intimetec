#include <iostream>
#pragma pack(push, 1)
class A
{
public:
    A() : value(34.2)
    {
        std::cout << "Constructor of A called" << std::endl;
        int data = 10;
        ch = 'h';
    }

    int getdata()
    {
        return data;
    }
    double getvalue()
    {
        return value;
    }
    int getconst()
    {
        return constantValue;
    }
    char getchar()
    {
        return ch;
    }

private:
    int data;
    double value;
    const int constantValue = 42;
    char ch;
};

int main()
{
    A a;
    std::cout << "Size of A: " << sizeof(a) << std::endl;
    std::cout << a.getdata();
    std::cout << a.getvalue();
    std::cout << a.getconst();
    std::cout << a.getchar();

    return 0;
}
