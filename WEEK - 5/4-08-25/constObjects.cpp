#include <iostream>
using namespace std;

class A
{
private:
    int b = 4;
    int c = this->b;
    int a;

public:
    A() : a(5)
    {
    }
    void setA(int a)
    {
        this->a = a;
    }

    int getC()
    {
        return c;
    }

    // ~A()
    // {
    //     cout << "Destructor" << endl;
    // };
    void getA() const
    {
        cout << a << endl;
    }
};

int main()
{

    A obj1;
    const A obj2;
    obj1.setA(10);
    obj1.getA();
    // obj2.setA(10); //error
    obj2.getA();

    cout << obj1.getC() << endl;
    return 0;
}