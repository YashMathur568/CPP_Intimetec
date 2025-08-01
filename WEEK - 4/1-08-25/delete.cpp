#include <iostream>
using namespace std;

class A
{
private:
    int a;

public:
    A()
    {
        cout << "Constructor" << endl;
    }

    ~A()
    {
        cout << "Dest" << endl;
    }
};

int main()
{
    // A *ptr = new A[3];
    // delete ptr;

    int *ptr1 = new int[5]{1, 2, 3, 4, 5};
    delete[] ptr1;
    // delete ptr1;
}