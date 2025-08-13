#include <iostream>
#include <string>

int main()
{
    std::string names[3] = {"Alice", "Bob", "Charlie"};
    int index;

    std::cout << "Enter index to print (0 - 2): ";
    std::cin >> index;

    std::cout << " Picked: " << names[index] << std::endl;

    int x, y;
    std::cout << "Enter two integers: ";
    std::cin >> x >> y;

    int result = x / y;
    std::cout << "Result: " << result << std::endl;

    int *ptr = new int(34);
    delete ptr;
    std::cout << "Dangling pointer value: " << *ptr << std::endl;

    return 0;
}
