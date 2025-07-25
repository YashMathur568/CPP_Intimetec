#include <iostream>

int *getDanglingPointer()
{
    int local = 42;
    return &local;
}

int *getFreedPointer()
{
    int *ptr = new int(100);
    delete ptr;
    return ptr;
}

int &getDanglingReference()
{
    int temp = 55;
    return temp;
}

int main()
{
    int *p1 = getDanglingPointer();
    std::cout << "Dangling Stack Pointer: " << *p1 << std::endl;

    int *p2 = getFreedPointer();
    std::cout << "Dangling Freed Pointer: " << *p2 << std::endl;

    int &ref = getDanglingReference();
    std::cout << "Dangling Reference: " << ref << std::endl;

    return 0;
}
