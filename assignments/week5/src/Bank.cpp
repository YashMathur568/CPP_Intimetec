#include "Bank.h"
#include <iostream>
using namespace std;

bool Bank::createAccount(AccountHolder &accountHolder)
{
    if (accountCount < 100)
    {
        Account newAccount;
        newAccount.setAccountNumber(accountCount + 1);
        newAccount.setBalance(0.0);
        accounts[accountCount] = newAccount;
        accountHolders[accountCount++] = accountHolder;
        return true;
    }
    return false;
}

Account *Bank::searchAccountByNumber(int accountNumber)
{
    for (int i = 0; i < accountCount; ++i)
    {
        if (accounts[i].getAccountNumber() == accountNumber)
        {
            return &accounts[i];
        }
    }
    return nullptr;
}

void Bank::closeAccount(int accountNumber)
{
    for (int i = 0; i < accountCount; ++i)
    {
        if (accounts[i].getAccountNumber() == accountNumber)
        {
            for (int j = i; j < accountCount - 1; ++j)
            {
                accounts[j] = accounts[j + 1];
            }
            --accountCount;
            break;
        }
    }
}