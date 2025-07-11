#include <iostream>
#include <stdexcept>
using namespace std;

double divide(double a, double b)
{
    if (b == 0)
    {
        throw runtime_error("Cannot divide by zero");
    }
    return a / b;
}

int main()
{
    double num1, num2;

    cout << "Enter numerator";
    cin >> num1;

    cout << "Enter denominator";
    cin >> num2;

    try
    {
        double result = divide(num1, num2);
        cout << "Result " << result << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Error " << e.what() << endl;
    }
    return 0;
}
