class A
{

public:
    int a = 4;
    int b = 8;
    bool operator==(const A &other) const
    {
        return a == other.a && b == other.b;
    }
};

class B
{
public:
    int a = 4;
    int b = 8;
    bool operator==(const B &other) const
    {
        return a == other.a && b == other.b;
    }
};

bool compareAB(const A &objA, const B &objB)
{
    return objA.a == objB.a && objA.b == objB.b;
}