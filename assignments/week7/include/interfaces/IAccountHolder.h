#ifndef IACCOUNTHOLDER_H
#define IACCOUNTHOLDER_H

#include "User.h"
#include "IAccount.h"

class IAccountHolder
{
public:
    virtual int getUserId() = 0;
    virtual std::string getName() = 0;
    virtual UserType getUserType() = 0;
    virtual bool authenticate(int userId, std::string password) = 0;
    virtual IAccount &getAccount() = 0;
    virtual void depositToAccount(double amount) = 0;
    virtual void withdrawFromAccount(double amount) = 0;
    virtual double checkBalance() = 0;
    virtual void viewMiniStatement() = 0;
    virtual void viewFullStatement() = 0;
    virtual ~IAccountHolder() = default;
};

#endif