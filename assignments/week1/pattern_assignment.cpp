#include <iostream>

using namespace std;

void printUpperHalf(int totalRows)
{
    for (int row = 0; row < (totalRows / 2) + 1; row++)
    {
        for (int column = 0; column <= row; column++)
        {
            if (column == totalRows / 2)
            {
                continue;
            }
            if (column % 2 == 0)
            {

                cout << "1 ";
            }
            else
            {

                cout << "0 ";
            }
        }
        for (int space = 0; space < totalRows - (2 * row) - 2; space++)
        {
            cout << "  ";
        }
        for (int column = 0; column <= row; column++)
        {
            if (column % 2 == 0)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void printLowerHalf(int totalRows)
{
    for (int row = 0; row < totalRows / 2; row++)
    {
        for (int column = 0; column < (totalRows / 2) - row; column++)
        {
            if (column % 2 == 0)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }

        for (int space = 0; space < 2 * row + 1; space++)
        {
            cout << "  ";
        }

        for (int column = 0; column < (totalRows / 2) - row; column++)
        {

            if (column % 2 == 0)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void makePattern(int totalRows)
{

    printUpperHalf(totalRows);

    printLowerHalf(totalRows);
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