#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> vec = {"Hello", "World"};
    // for (string word : vec)
    // {
    //     word = "Modified";
    // }
    for (string &word : vec)
    {
        word = "Modified";
    }

    for (string word : vec)
    {
        cout << word << endl;
        ;
    }
}