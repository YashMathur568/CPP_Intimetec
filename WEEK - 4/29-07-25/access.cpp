#include <iostream>

class Secret
{
private:
    int hidden = 42;

public:
    int getHidden()
    {
        return hidden;
    }
};

int main()
{
    Secret s;
    int *p = (int *)&s;
    std::cout << *p << "\n"; // Accessing private member with a pointer
}