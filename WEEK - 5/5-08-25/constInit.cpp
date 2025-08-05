#include <iostream>
using namespace std;

class A
{
    int a;
    int b;

public:
    A(int i, int j) : a(i), b(j)
    {
        int k = 4;
        cout << "A constructor body" << endl;
    }

    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
};

class B : public A
{
    int c;
    int d;

public:
    B(int p, int q) : c(p), d(q), A(1, 2)
    {
        cout << "B constructor body" << endl;
    }

    int getC()
    {
        return c;
    }
    int getD()
    {
        return d;
    }
};

int main()
{
    B objb(3, 4);
    cout << objb.getA() << endl;
    cout << objb.getB() << endl;
    cout << objb.getC() << endl;
    cout << objb.getD() << endl;

    return 0;
}