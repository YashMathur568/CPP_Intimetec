#include <iostream>
// using namespace std;

//Nested Function Definations are Illegal in c++
// int main() {
//     void print(int x) {
//         cout << x;
//     }
//     return 0;
// }

void print(int x) {
    std::cout << x;
}

int main() {
    print(3.14);
}
