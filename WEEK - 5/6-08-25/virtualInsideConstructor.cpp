#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base constructor\n";
        speak();
    }
    virtual void speak()
    {
        cout << "Base::speak\n";
    }
    virtual ~Base()
    {
        cout << "Base destructor\n";
        speak();
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived constructor\n";
    }
    void speak() override
    {
        cout << "Derived::speak\n";
    }
    ~Derived()
    {
        cout << "Derived destructor\n";
    }
};

int main()
{
    Derived obj;
    return 0;
}