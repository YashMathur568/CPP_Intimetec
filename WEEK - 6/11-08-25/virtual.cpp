#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "A Constructor\n"; }
    virtual ~A() { cout << "A Destructor\n"; }
};

// class B : virtual public A
class B : public A
{
public:
    B() { cout << "B Constructor\n"; }
    ~B() { cout << "B Destructor\n"; }
};

// class C : virtual public A
class C : public A
{
public:
    C() { cout << "C Constructor\n"; }
    ~C() { cout << "C Destructor\n"; }
};

class D : public B, public C
{
public:
    D() { cout << "D Constructor\n"; }
    ~D() { cout << "D Destructor\n"; }
};

int main()
{
    cout << "Creating object...\n";
    D obj;
    cout << "Object created.\n";

    cout << "Destroying object...\n";
    return 0;
}
