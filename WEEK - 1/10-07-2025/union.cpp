#include <iostream>
#include <cstring>

union Data
{
    int intValue;
    float floatValue;
    char text[20];
};

int main()
{
    Data d;

    d.intValue = 42;
    std::cout << "intValue: " << d.intValue << "\n";

    d.floatValue = 3.14f;
    std::cout << "floatValue: " << d.floatValue << "\n";

    std::strcpy(d.text, "Yash Mathur");
    std::cout << "text: " << d.text << "\n";

    std::cout << "value after string: " << d.intValue << "\n";

    return 0;
}
