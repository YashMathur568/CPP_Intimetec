#include <iostream>

int main()
{
    int x{5};
    int *ptr{&x};

    // std::cout << *ptr << '\n';

    {
        int y{67};
        ptr = &y;

        // std::cout << *ptr << '\n';
    }

    // std::cout << *ptr << '\n';

    const int z{5};
    const int *pt{&z};

    int p{6};
    pt = &p;
    std::cout << *pt;

    return 0;
}