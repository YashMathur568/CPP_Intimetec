#include <iostream>

struct Rectangle
{
    int width{};
    int height{};

    void print()
    {
        std::cout << "Rectangle(" << width << " x " << height << ")\n";
    }

    bool isEqual(Rectangle other)
    {
        return (width == other.width) && (height == other.height);
    }
};

int main()
{
    Rectangle r1{10, 20};
    Rectangle r2{15, 25};
    std::cout << "r1: ";
    r1.print();
    std::cout << "r2: ";
    r2.print();
    std::cout << "r1 and r2 " << (r1.isEqual(r2) ? "are equal\n" : "are not equal\n");
    return 0;
}
