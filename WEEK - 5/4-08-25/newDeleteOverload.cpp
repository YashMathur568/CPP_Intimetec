#include <iostream>
#include <cstdlib>

void *operator new(size_t size)
{
    std::cout << "Custom new: allocating " << size << " bytes\n";
    void *p = std::malloc(size);
    return p;
}

void operator delete(void *pointer)
{
    std::cout << "Custom delete: deallocating memory\n";
    std::free(pointer);
}

void *operator new[](size_t size)
{
    std::cout << "Custom new[]: allocating " << size << " bytes\n";
    void *p = std::malloc(size);
    return p;
}

void operator delete[](void *ptr)
{
    std::cout << "Custom delete[]: deallocating memory\n";
    std::free(ptr);
}

class A
{
    int a;

public:
    A() { std::cout << "Constructor\n"; }
    ~A() { std::cout << "Destructor\n"; }
};

int main()
{
    // A *ptr = new A;
    // delete[] ptr;
    // delete ptr;

    A *ptr2 = new A[3];
    delete ptr2;
    // delete[] ptr2;

    return 0;
}
