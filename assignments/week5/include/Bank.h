#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include "AccountHolder.h"
#include <cstdlib>
#include <ctime>

class Bank
{
private:
    Account accounts[100];
    AccountHolder accountHolders[50];
    int accountCount;

public:
    Bank() : accountCount(0)
    {
        srand(time(0));
    }

    int getRandomUserId()
    {
        return rand() % 1000 + 1;
    }
    int getRandomAccountNumber()
    {
        return rand() % 10000 + 1000;
    }

    void createAccountForAccountHolder(AccountHolder &accountHolder)
    {
        int accountNumber = getRandomAccountNumber();
        Account newAccount(accountNumber);
        accountHolders[accountCount++] = accountHolder;
        accounts[accountCount - 1] = newAccount;
    }

    bool createAccount(AccountHolder &accountHolder);
    Account *searchAccountByNumber(int accountNumber);
    void closeAccount(int accountNumber);
};

#endif
