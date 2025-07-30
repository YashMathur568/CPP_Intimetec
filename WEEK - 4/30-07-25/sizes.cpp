#include <iostream>

using namespace std;

class A
{
    bool a;
};

class B
{
};

int main()
{
    int a;
    A a1;
    A a2;
    cout << sizeof(a) << endl;
    cout << sizeof(A) << endl;
    cout << "Address of a1: " << &a1 << endl;
    cout << "Address of a2: " << &a2 << endl;

    B b1;
    B b2;
    cout << "Address of b1: " << &b1 << endl;
    cout << "Address of b2: " << &b2 << endl;

    cout << &a1;
}
