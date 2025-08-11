#include <iostream>
using namespace std;

int multiply(int a, int b)
{
    int result = a * b;
    return result;
}

int main()
{
    int x = 3;
    int y = 4;
    int z = multiply(x, y);
    cout << "Answer: " << z << endl;
    return 0;
}
