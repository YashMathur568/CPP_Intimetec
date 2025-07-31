#include <iostream>
using namespace std;

class A
{
private:
    int a = 42;
    int c = a;
    const int b;
    static int ss;

public:
    A(int r) : a(20), b(40)
    {
        cout << "I am constructor\n";
    }

    void getvalues()
    {
        cout << a << " " << b << " " << c << " " << ss << " " << endl;
    }
};
int A::ss = 10;

int main()
{
    A obj(90);
    obj.getvalues();
}
