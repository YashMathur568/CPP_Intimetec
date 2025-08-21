#ifndef BANKINTERFACE_H
#define BANKINTERFACE_H

#include "AccountHolder.h"
#include "Admin.h"

class BankInterface
{
public:
    virtual ~BankInterface() {}

    virtual bool createAccount(const AccountHolder &accHolder, Admin &admin) = 0;
    virtual Account *searchAccount(int accountNumber, Admin &admin) = 0;
    virtual void closeAccount(int accountNumber, Admin &admin) = 0;
    virtual AccountHolder *loginAccountHolder(int inputUserId, std::string inputPassword) = 0;
    virtual int generateUniqueUserId() = 0;
    virtual int generateUniqueAccountNumber() = 0;
    virtual void resizeAccountHolders() = 0;
};

#endif
