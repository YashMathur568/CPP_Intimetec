#include "InputValidation.h"
#include <iostream>

bool isValidAge(int age)
{
    return age > 0;
}

bool isValidEmail(const std::string &email)
{
    int CountofAt = 0;
    bool dotAfterAt = false;
    bool atFound = false;

    for (int i = 0; i < email.size(); i++)
    {
        if (email[i] == ' ')
            return false;
        if (email[i] == '@')
        {
            CountofAt++;
            atFound = true;
        }
        if (atFound && email[i] == '.')
            dotAfterAt = true;
    }
    return CountofAt == 1 && dotAfterAt;
}

bool isValidContact(const std::string &contact)
{
    if (contact.length() < 7 || contact.length() > 15)
        return false;

    for (int i = 0; i < contact.length(); ++i)
    {
        if (contact[i] < '0' || contact[i] > '9')
            return false;
    }
    return true;
}

bool isValidPassword(const std::string &password)
{
    return password.length() >= 6;
}

void flushInputBuffer()
{
    while (getchar() != '\n')
    {
    };
}

int getValidatedInt()
{
    int value;
    while (true)
    {
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n' || value <= 0)
        {
            std::cout << "Invalid input. Please enter a valid positive and non-zero number.\n";
            std::cin.clear();
            flushInputBuffer();
        }
        else
        {
            flushInputBuffer();
            return value;
        }
    }
}

double getValidatedDouble()
{
    double value;
    while (true)
    {
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n' || value <= 0)
        {
            std::cout << "Invalid input. Please enter a valid positive and non-zero number.\n";
            std::cin.clear();
            flushInputBuffer();
        }
        else
        {
            flushInputBuffer();
            return value;
        }
    }
}