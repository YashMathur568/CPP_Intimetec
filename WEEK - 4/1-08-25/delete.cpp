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
{ // Making array of objects
    A *ptr = new A[3];
    // delete[] ptr;
    delete ptr;

    // Single object
    // A *a = new A();
    // delete a;

    // primitive type
    // int *ptr1 = new int[5]{1, 2, 3, 4, 5};
    // // delete[] ptr1;
    // delete ptr1;
}
