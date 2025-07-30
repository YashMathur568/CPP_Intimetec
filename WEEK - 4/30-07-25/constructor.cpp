#include <iostream>
#include <string>

using namespace std;

// class A
// {
// public:
//     int a;
// };

// int main()
// {

//     A a;
//     cout << a.a << endl;
//     return 0;
// }

class A
{
public:
    string name;
    int id;

    A()
    {
        cout << "A's constructor\n";
    }

    void print()
    {
        cout << "name: " << name << ", id: " << id << "\n";
    }
};

int main()
{
    A obj;
    obj.print(); // name is default-initialized by string's constructor but id is garbage.
}
