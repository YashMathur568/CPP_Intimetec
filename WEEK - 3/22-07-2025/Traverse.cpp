#include <iostream>

using namespace std;

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};
    int *begin = arr;
    int *end = (arr + size(arr));

    for (int *it = begin; it != end; it++)
    {
        cout << *it;
    }
}

// #include <iostream>
// #include <stdexcept>

// class IntArray {
// private:
//     int* m_array{};
//     int m_length{};

// public:
//     IntArray(int length) {

//         m_array = new int[static_cast<std::size_t>(length)]{};
//         m_length = length;
//     }

//     ~IntArray() {
//         delete[] m_array;
//     }

//     void setValue(int index, int value) {

//         m_array[index] = value;
//     }

//     int getValue(int index) {
//         return m_array[index];
//     }

//     int getLength() const {
//         return m_length;
//     }
// };

// int main() {
//         IntArray ar(10);

//         for (int count{0}; count < ar.getLength(); ++count)
//             ar.setValue(count, count + 1);

//         std::cout << "The value of element 5 is: " << ar.getValue(5) << '\n';

//     return 0;
// }
