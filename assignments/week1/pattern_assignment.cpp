#include <iostream>

using namespace std;

void makePattern(int Totalrows)
{
    for (int row = 0; row < (Totalrows / 2) + 1; row++)
    {
        for (int column = 0; column <= row; column++)
        {
            if (column % 2 == 0)
            {
                if (column == Totalrows / 2)
                {
                    continue;
                }
                cout << 1;
            }
            else
            {
                if (column == Totalrows / 2)
                {
                    continue;
                }
                cout << 0;
            }
        }
        for (int space = 0; space < Totalrows - (2 * row) - 2; space++)
        {
            cout << " ";
        }
        for (int column = 0; column <= row; column++)
        {
            if (column % 2 == 0)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        cout << endl;
    }

    for (int row = 0; row < Totalrows / 2; row++)
    {
        for (int column = 0; column < (Totalrows / 2) - row; column++)
        {
            if (column % 2 == 0)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }

        for (int space = 0; space < 2 * row + 1; space++)
        {
            cout << " ";
        }

        for (int column = 0; column < (Totalrows / 2) - row; column++)
        {
            if (column % 2 == 0)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        cout << endl;
    }
}

int main()
{
    cout << "Enter the number of rows in pattern" << endl;
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << "Please Enter Valid Number Of Rows" << endl;
        exit(1);
    }
    n = 2 * n + 1;
    makePattern(n);
    return 0;
}