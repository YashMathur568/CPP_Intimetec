#ifndef BANK_H
#define BANK_H

#include "BankInterface.h"
#include "AccountHolder.h"
#include "Admin.h"

#define INITIAL_ACCOUNTHOLDER_COUNT 10

class Bank : public BankInterface
{
    AccountHolder **accountHolders;
    int accountHolderCount;
    int accountHolderCapacity;

public:
    Bank();
    ~Bank();

    bool createAccount(const AccountHolder &accHolder, Admin &admin) override;
    Account *searchAccount(int accountNumber, Admin &admin) override;
    void closeAccount(int accountNumber, Admin &admin) override;
    AccountHolder *loginAccountHolder(int inputUserId, std::string inputPassword) override;
    int generateUniqueUserId() override;
    int generateUniqueAccountNumber() override;
    void resizeAccountHolders() override;
};

#endif
