#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
    int accountNumber;
    double balance;

public:
    Account(int accNumber);

    void deposit(double amount);

    double getBalance() const;

    int getAccountNumber() const;
};

#endif
