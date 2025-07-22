#include <iostream>
#include <array>

using namespace std;

int main()
{
    int x = 34;
    int *ptr = &x;
    // cout << *(ptr);

    int arr[] = {1, 2, 3, 4, 5};
    int *ptr2 = arr;

    for (int i = 0; i < 5; i++)
    {
        // cout << *(ptr2 + i);
    }

    int a = NULL;
    cout << a << endl;

    return 0;
}