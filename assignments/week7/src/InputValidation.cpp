#include "InputValidation.h"
#include <iostream>

bool isValidAge(int age)
{
    return (age > 0 && age < 200);
}

bool isValidEmail(std::string &email)
{
    int atCount = 0;
    bool dotAfterAt = false;
    bool atFound = false;

    for (int index = 0; index < email.size(); index++)
    {
        if (email[index] == ' ')
            return false;
        if (email[index] == '@')
        {
            atCount++;
            atFound = true;
        }
        if (atFound && email[index] == '.')
            dotAfterAt = true;
    }
    return atCount == 1 && dotAfterAt;
}

bool isValidContact(std::string &contact)
{
    if (contact.length() < 7 || contact.length() > 15)
        return false;

    for (int digitIndex = 0; digitIndex < contact.length(); ++digitIndex)
    {
        if (contact[digitIndex] < '0' || contact[digitIndex] > '9')
            return false;
    }
    return true;
}

bool isValidPassword(std::string &password)
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
