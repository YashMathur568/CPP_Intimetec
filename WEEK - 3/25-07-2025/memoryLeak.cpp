#include <iostream>

int main()
{
    int *a = new int(100);
    std::cout << "Leaked value: " << *a << std::endl;

    int *b = new int(200);
    delete b;
    std::cout << "Use after delete: " << *b << std::endl;

    int *doubleDel = new int(300);
    delete doubleDel;
    delete doubleDel;

    int x = 10;
    int *notWithNew = &x;
    // delete notWithNew;

    int *c = new int(500);
    std::cout << "Proper " << *c << std::endl;
    delete c;

    return 0;
}
