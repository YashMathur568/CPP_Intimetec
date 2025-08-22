#ifndef BANK_H
#define BANK_H

#include "AccountHolder.h"
#include "Admin.h"
#include "interfaces/IBank.h"

#define INITIAL_ACCOUNTHOLDER_COUNT 10

class Bank : public IBank
{
private:
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
    void resizeAccountHolders();
};

#endif