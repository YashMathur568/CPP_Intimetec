#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    int x{52};
    double d{3.23};
    int &ref{x};
    // int &invalidRef{d};     // conversion of double to int is narrowing conversion, disallowed by list initialization
    // double &invalidRef2{x}; // invalid: non-const lvalue reference can't bind to rvalue (result of converting x to double)

    x = 4;
    std::cout << typeid(x).name() << '\n';
    std::cout << typeid(&x).name() << '\n';

    return 0;
}