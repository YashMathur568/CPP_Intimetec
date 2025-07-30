#include <iostream>
using namespace std;

class Box
{
    int length, breadth, height;

public:
    Box()
    {
        length = breadth = height = 1;
    }

    Box(int l)
    {
        length = breadth = height = l;
    }

    Box(int l, int b, int h)
    {
        length = l;
        breadth = b;
        height = h;
    }

    void printVolume()
    {
        cout << "Volume: " << length * breadth * height << "\n";
    }
};

int main()
{
    Box b1;
    Box b2(5);
    Box b3(2, 3, 4);

    b1.printVolume();
    b2.printVolume();
    b3.printVolume();

    return 0;
}