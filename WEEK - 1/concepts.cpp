#include <iostream>
using namespace std;

//Nested Function Definations are Illegal in c++

// int main() {
//     void print(int x) {
//         cout << x;
//     }
//     return 0;
// }

//Implicit Typecasting

// void print(int x) {
//     std::cout << x;
// }
// int main() {
//     print(3.14);
// }

//Types of namespaces

// 1. Names namespace
// namespace MyNamespace {
//     int value = 10;
// }

// 2. Unnamed namespace
//Only accessible in that cpp file
// namespace {
//     int hidden = 42;  // Only accessible in this translation unit
// }

// 3. Nested Namespace
// namespace A {
//     namespace B {
//         void greet() {}
//     }
// }
//OR
// namespace A::B {
//     void greet() {}
// }
// Usage-> A::B::greet();

// 4. Inline Namespace
// Introduced in C++11 to support versioning. Members of an inline namespace are treated as if they belong to the outer namespace.
// namespace MyLib {
//     inline namespace v1 {
//         void doSomething();
//     }
//     namespace v2 {
//         void doSomething();
//     }
// }
// MyLib::doSomething();  // Calls v1 version by default
// MyLib::v2::doSomething();  // Explicit version

int main(){
    int x {};      // value initialization (List Initialization)
    cout<<x;
    return 0;
}