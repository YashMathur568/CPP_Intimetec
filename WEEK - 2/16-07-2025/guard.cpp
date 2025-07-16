#include <iostream>

#define MACRO

int main()
{
#ifdef MACRO
    std::cout << "MACRO" << std::endl;
#endif

    // This will give error because we would have a #if with no expression
    // #if MACRO
    //     std::cout << "MACRO" << std::endl;
    // #endif

    return 0;
}