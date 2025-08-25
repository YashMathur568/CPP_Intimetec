#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void sortContainer(T &container)
{
    std::sort(std::begin(container), std::end(container));
}

int main()
{
    int arr[] = {5, 2, 9, 1, 5, 6};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Before sorting the array: ";
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    sortContainer(arr);

    std::cout << "After sorting the array: ";
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::vector<double> vec = {3.4, 2.1, 5.9, 4.6, 1.3};

    std::cout << "Before sorting the vector: ";
    for (auto val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    sortContainer(vec);

    std::cout << "After sorting the vector: ";
    for (auto val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
