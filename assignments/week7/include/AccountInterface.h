#ifndef ACCOUNTINTERFACE_H
#define ACCOUNTINTERFACE_H

#include <string>

class AccountInterface
{
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual double getBalance() = 0;
    virtual void printMiniStatement() = 0;
    virtual void printFullStatement() = 0;
    virtual int getAccountNumber() = 0;
    virtual ~AccountInterface() {}
};

#endif
