#include <iostream>
using namespace std;

class A
{
    int a;

public:
    void func() // const
    {
        a = 4; // error: assignment of member ‘A::a’ in read-only object
    }
    int getValue() const
    {
        return a;
    }
};

int main()
{
    A obj;
    obj.func();
    cout << obj.getValue() << endl;
    return 0;
}