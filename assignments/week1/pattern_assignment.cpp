#include <iostream>

using namespace std;

void makePattern(int Totalrows)
{
    for (int row = 0; row < (Totalrows / 2) + 1; row++)
    {
        for (int column = 0; column <= row; column++)
        {
            if (column == Totalrows / 2)
            {
                continue;
            }
            if (column % 2 == 0)
            {

                cout << 1;
            }
            else
            {

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
    int size;
    while (true)
    {
        cout << "Enter the size of the pattern (positive integer): ";
        cin >> size;

        if (cin.fail() || size <= 0)
        {
            cout << "Invalid input. Please enter a positive number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
        {
            break;
        }
    }
    size = 2 * size + 1;
    makePattern(size);
    return 0;
}