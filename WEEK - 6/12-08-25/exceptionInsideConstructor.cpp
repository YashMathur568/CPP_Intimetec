#include <iostream>
#include <string>

class A
{
public:
    A() { std::cout << "A constructed\n"; }
    ~A() { std::cout << "A destroyed\n"; }
};

class B
{
public:
    B() { std::cout << "B constructed\n"; }
    ~B() { std::cout << "B destroyed\n"; }
};

class MyClass
{
    A a;
    B b;
    int *ptr;

public:
    MyClass()
    {
        std::cout << "MyClass constructor body starts\n";
        ptr = new int[5];
        std::cout << "Resource allocated\n";
        throw std::runtime_error("Constructor failed!");
    }

    ~MyClass()
    {
        std::cout << "Destructor of MyClass\n";
        delete[] ptr;
    }
};

int main()
{
    try
    {
        MyClass obj;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
}
