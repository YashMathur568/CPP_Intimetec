#include <iostream>
using namespace std;

class A;
class B;
class C;
void printAll(A &, B &, C &);

class A
{
    int a = 1;
    friend void printAll(A &, B &, C &);
};
class B
{
    int b = 2;
    friend void printAll(A &, B &, C &);
};
class C
{
    int c = 3;
    friend void printAll(A &, B &, C &);
};
void printAll(A &aObj, B &bObj, C &cObj)
{
    std::cout << "A: " << aObj.a << "\n";
    std::cout << "B: " << bObj.b << "\n";
    std::cout << "C: " << cObj.c << "\n";
}

int main()
{
    A obj1;
    B obj2;
    C obj3;
    printAll(obj1, obj2, obj3);
    return 0;
}