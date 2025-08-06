#include <iostream>
using namespace std;

class A
{
public:
    int x;
    A(int val) : x(val) { cout << "A constructor: x = " << x << endl; }
};

class B : virtual public A
{
public:
    B() : A(0)
    {
        cout << "B constructor\n";
    }
};

class C : virtual public A
{
public:
    C() : A(0)
    {
        cout << "C constructor\n";
    }
};

class D : public B, public C
{
public:
    D() : A(42)
    {
        cout << "D constructor\n";
    }
};

int main()
{
    D obj;
    return 0;
}
