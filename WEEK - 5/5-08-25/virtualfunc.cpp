#include <iostream>
using namespace std;

class base
{
public:
    virtual void func1()
    {
        cout << "func1 base" << endl;
    }
    void func2()
    {
        cout << "func2 base" << endl;
    }
};

class derived : public base
{
public:
    void func1()
    {
        cout << "func1 derived" << endl;
    }
    void func2()
    {
        cout << "func2 derived" << endl;
    }
    void func3()
    {
        cout << "func3 derived" << endl;
    }
};

int main()
{
    // base b;
    // b.func1();
    // b.func2();

    // derived d;
    // d.func1();
    // d.func2();

    base *bptr = new derived();
    bptr->func1();
    bptr->func2();
    // bptr->func3();  // Base has no member func3

    derived *dptr = new derived();
    dptr->func1();
    dptr->func2();
    return 0;
}