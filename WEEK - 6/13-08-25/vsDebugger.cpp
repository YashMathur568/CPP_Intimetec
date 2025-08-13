#include <iostream>
#include <string>

int main()
{
    std::string names[3] = {"Alice", "Bob", "Charlie"};
    int index;

    std::cout << "Enter index to print (0 - 2): ";
    std::cin >> index;

    // Bug 1: No bounds checking on array
    std::cout << "You picked: " << names[index] << std::endl;

    // Bug 2: Division by zero possible
    int x, y;
    std::cout << "Enter two integers (x y): ";
    std::cin >> x >> y;

    int result = x / y; // Possible divide-by-zero crash
    std::cout << "Result: " << result << std::endl;

    // Bug 3: Dangling pointer
    int *ptr = new int(42);
    delete ptr;
    std::cout << "Dangling pointer value: " << *ptr << std::endl; // Undefined behavior

    return 0;
}
