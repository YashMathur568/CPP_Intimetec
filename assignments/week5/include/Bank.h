#ifndef BANK_H
#define BANK_H

#include "AccountHolder.h"
#include "Admin.h"
#include <string>

#define MAX_USERS 100

class Bank
{
    AccountHolder accountHolders[MAX_USERS];
    int accountHolderCount;

public:
    Bank();

    bool createAccount(const AccountHolder &accHolder, Admin &admin);
    Account *searchAccount(int accountNumber, Admin &admin);
    void closeAccount(int accountNumber, Admin &admin);
    AccountHolder *loginAccountHolder(int inputUserId, std::string inputPassword);
    int generateUniqueUserId();
    int generateUniqueAccountNumber();
};

#endif