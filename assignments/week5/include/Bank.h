#ifndef BANK_H
#define BANK_H

#include "AccountHolder.h"
#include "Admin.h"

#define INITIAL_ACCOUNTHOLDER_COUNT 10

class Bank
{
    AccountHolder **accountHolders;
    int accountHolderCount;
    int accountHolderCapacity;

public:
    Bank();
    ~Bank();

    bool createAccount(const AccountHolder &accHolder, Admin &admin);
    Account *searchAccount(int accountNumber, Admin &admin);
    void closeAccount(int accountNumber, Admin &admin);
    AccountHolder *loginAccountHolder(int inputUserId, std::string inputPassword);
    int generateUniqueUserId();
    int generateUniqueAccountNumber();
    void resizeAccountHolders();
};

#endif