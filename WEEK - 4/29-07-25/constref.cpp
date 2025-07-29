#include <iostream>

struct Date
{
    int year{};
    int month{};
    int day{};

    // void print()    //This is not running because we are calling it with a const ref of non-const
    void print() const // This will work because const can be called by const and non-const
    {
        std::cout << year << '/' << month << '/' << day;
    }
};

void doSomething(const Date &date)
{
    date.print(); // now const ref
}

int main()
{
    Date today{2020, 10, 14}; // non-const
    today.print();

    doSomething(today);

    return 0;
}