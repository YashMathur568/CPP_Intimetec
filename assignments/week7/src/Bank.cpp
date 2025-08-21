#include "Bank.h"
#include "AccountHolder.h"
#include <iostream>

Bank::Bank()
    : accountHolderCount(0), accountHolderCapacity(INITIAL_ACCOUNTHOLDER_COUNT)
{
    accountHolders = new AccountHolder *[accountHolderCapacity];
}

Bank::~Bank()
{
    for (int accountHolderIndex = 0; accountHolderIndex < accountHolderCount; ++accountHolderIndex)
    {
        delete accountHolders[accountHolderIndex];
    }
    delete[] accountHolders;
}

int Bank::generateUniqueUserId()
{
    int userId;
    bool exists;
    do
    {
        userId = rand() % 9000 + 1000;
        exists = false;
        for (int accountHolderIndex = 0; accountHolderIndex < accountHolderCount; accountHolderIndex++)
        {
            if (accountHolders[accountHolderIndex]->getUserId() == userId)
            {
                exists = true;
                break;
            }
        }
    } while (exists);
    return userId;
}

int Bank::generateUniqueAccountNumber()
{
    int accountNumber;
    bool exists;
    do
    {
        accountNumber = rand() % 900000 + 100000;
        exists = false;
        for (int accountHolderIndex = 0; accountHolderIndex < accountHolderCount; accountHolderIndex++)
        {
            if (accountHolders[accountHolderIndex]->getAccount().getAccountNumber() == accountNumber)
            {
                exists = true;
                break;
            }
        }
    } while (exists);
    return accountNumber;
}

bool Bank::createAccount(const AccountHolder &accHolder, Admin &admin)
{
    if (admin.getUserType() != UserType::Admin)
        return false;

    if (accountHolderCount == accountHolderCapacity)
    {
        resizeAccountHolders();
    }

    accountHolders[accountHolderCount++] = new AccountHolder(accHolder);

    return true;
}

Account *Bank::searchAccount(int accountNumber, Admin &admin)
{
    if (admin.getUserType() != UserType::Admin)
        return nullptr;

    for (int accountHolderIndex = 0; accountHolderIndex < accountHolderCount; accountHolderIndex++)
    {
        if (accountHolders[accountHolderIndex]->getAccount().getAccountNumber() == accountNumber)
            return &accountHolders[accountHolderIndex]->getAccount();
    }
    return nullptr;
}

void Bank::closeAccount(int accountNumber, Admin &admin)
{
    if (admin.getUserType() != UserType::Admin)
    {
        std::cout << "Permission denied! Only admins can close accounts.\n";
        return;
    }

    for (int accountHolderIndex = 0; accountHolderIndex < accountHolderCount; accountHolderIndex++)
    {
        if (accountHolders[accountHolderIndex]->getAccount().getAccountNumber() == accountNumber)
        {
            delete accountHolders[accountHolderIndex];
            for (int shiftIndex = accountHolderIndex; shiftIndex < accountHolderCount - 1; shiftIndex++)
            {
                accountHolders[shiftIndex] = accountHolders[shiftIndex + 1];
            }
            accountHolderCount--;
            std::cout << "Account closed successfully\n";
            return;
        }
    }

    std::cout << "Account not found!\n";
}

AccountHolder *Bank::loginAccountHolder(int inputUserId, std::string inputPassword)
{
    for (int accountHolderIndex = 0; accountHolderIndex < accountHolderCount; accountHolderIndex++)
    {
        if (accountHolders[accountHolderIndex]->authenticate(inputUserId, inputPassword))
        {
            return accountHolders[accountHolderIndex];
        }
    }
    return nullptr;
}

void Bank::resizeAccountHolders()
{
    accountHolderCapacity *= 2;

    AccountHolder **newAccountHolders = new AccountHolder *[accountHolderCapacity];
    for (int accountHolderIndex = 0; accountHolderIndex < accountHolderCount; accountHolderIndex++)
    {
        newAccountHolders[accountHolderIndex] = accountHolders[accountHolderIndex];
    }

    delete[] accountHolders;
    accountHolders = newAccountHolders;
}