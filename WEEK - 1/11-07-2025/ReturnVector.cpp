#include <iostream>
#include <vector>

using namespace std;

vector<int> generateSquares(int n)
{
    vector<int> result;
    for (int i = 1; i <= n; i++)
    {
        result.push_back(i * i);
    }
    return result;
}

int main()
{
    int count;
    cout << "Enter how many squares you want";
    cin >> count;

    vector<int> squares = generateSquares(count);

    cout << "Squares ";
    for (int num : squares)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
