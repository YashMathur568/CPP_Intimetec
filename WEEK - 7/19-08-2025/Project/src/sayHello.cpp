#include <iostream>
#include <string>
using namespace std;

string sayHello(string str)
{
    if (str.length())
    {
        return ("Hello " + str);
    }
    else
    {
        return "Hello World";
    }
}
