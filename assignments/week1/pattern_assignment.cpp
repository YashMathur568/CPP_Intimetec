#include <iostream>

using namespace std;

void printUpperHalf(int totalRows)
{
    for (int row = 1; row <= (totalRows / 2); row++)
    {
        for (int column = 1; column <= row; column++)
        {
            if (column == (totalRows / 2) + 1)
            {
                continue;
            }
            if (column % 2 == 0)
            {

                cout << "0 ";
            }
            else
            {

                cout << "1 ";
            }
        }
        for (int space = 1; space <= totalRows - (2 * row); space++)
        {
            cout << "  ";
        }
        for (int column = 1; column <= row; column++)
        {
            if (column % 2 == 0)
            {
                cout << "0 ";
            }
            else
            {
                cout << "1 ";
            }
        }
        cout << endl;
    }
}

void printLowerHalf(int totalRows)
{
    int limiter;
    if (totalRows % 2 == 0)
    {
        limiter = (totalRows / 2);
    }
    else
    {
        limiter = (totalRows / 2) + 1;
    }
    for (int row = 0; row < limiter; row++)
    {
        for (int column = 0; column < limiter - row; column++)
        {
            if (totalRows % 2 != 0 && column == limiter - 1)
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

        int spaceLimiter;
        if (totalRows % 2 == 0)
        {
            spaceLimiter = 2 * row;
        }
        else
        {
            spaceLimiter = 2 * row - 1;
        }
        for (int space = 0; space < spaceLimiter; space++)
        {
            cout << "  ";
        }

        for (int column = 0; column < limiter - row; column++)
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
    makePattern(size);
    return 0;
}