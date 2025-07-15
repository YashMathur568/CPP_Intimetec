#include <iostream>
#include <string>
using namespace std;
// We can declare Class in header
class A
{
public:
    void printHello();
};

// we can declare functions in a header
int coffeeServings(int a, int b);

// We can define a struct
// A struct cannot be separated across .h and .cpp the way a function or class method can be.
// The compiler needs to know the full definition of the struct wherever it's used (not just a forward declaration)
struct student
{
    string name;
    int age;
};

#define PI 3.14