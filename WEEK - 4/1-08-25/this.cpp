#include <iostream>
using namespace std;

// class A
// {
// private:
//     // int a = 4;
//     int a = this->c;
//     int c = 5;

// public:
//     void getvalue() { cout << a << " " << c << endl; }
// };

// int main()
// {
//     A a;
//     a.getvalue();
//     return 0;
// }

class MyClass
{
private:
    int a = 334;
    int b = this->a;

public:
    MyClass(int value) : a(value)
    {
        std::cout << "Constructor called, this pointer address: " << this << std::endl;
    }

    void print()
    {
        std::cout << "this pointer address in print(): " << this << std::endl;
        std::cout << "Value of a: " << a << " " << b << std::endl;
    }
};

int main()
{
    MyClass obj(222);
    obj.print();
    return 0;
}
