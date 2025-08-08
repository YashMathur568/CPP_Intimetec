#include "Bank.h"
#include <iostream>

Bank::Bank() : accountHolderCount(0) {}

int Bank::generateUniqueUserId()
{
    int userId;
    bool exists;
    do
    {
        userId = rand() % 9000 + 1000;
        exists = false;
        for (int holderIndex = 0; holderIndex < accountHolderCount; holderIndex++)
        {
            if (accountHolders[holderIndex].getUserId() == userId)
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
        for (int holderIndex = 0; holderIndex < accountHolderCount; holderIndex++)
        {
            if (accountHolders[holderIndex].getAccount().getAccountNumber() == accountNumber)
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

    if (accountHolderCount < MAX_USERS)
    {
        accountHolders[accountHolderCount++] = accHolder;
        return true;
    }
    return false;
}

Account *Bank::searchAccount(int accountNumber, Admin &admin)
{
    if (admin.getUserType() != UserType::Admin)
        return nullptr;

    for (int holderIndex = 0; holderIndex < accountHolderCount; holderIndex++)
    {
        if (accountHolders[holderIndex].getAccount().getAccountNumber() == accountNumber)
            return &accountHolders[holderIndex].getAccount();
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

    for (int holderIndex = 0; holderIndex < accountHolderCount; ++holderIndex)
    {
        if (accountHolders[holderIndex].getAccount().getAccountNumber() == accountNumber)
        {
            for (int shiftIndex = holderIndex; shiftIndex < accountHolderCount - 1; shiftIndex++)
            {
                accountHolders[shiftIndex] = accountHolders[shiftIndex + 1];
            }
            accountHolderCount--;
            std::cout << "Account Closed Successfully\n";
            return;
        }
    }
    std::cout << "Account Not Found!\n";
}

AccountHolder *Bank::loginAccountHolder(int inputUserId, std::string inputPassword)
{
    for (int holderIndex = 0; holderIndex < accountHolderCount; holderIndex++)
    {
        if (accountHolders[holderIndex].authenticate(inputUserId, inputPassword))
        {
            return &accountHolders[holderIndex];
        }
    }
    return nullptr;
}
