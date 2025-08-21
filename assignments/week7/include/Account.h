#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "AccountInterface.h"
#include "Transaction.h"
#include <string>
#include <ctime>

class Account : public AccountInterface
{
private:
    int accountNumber;
    double balance;
    Transaction **transactions;
    int transactionCount;
    int transactionCapacity;

public:
    Account(int accNumber);
    ~Account();

    void deposit(double amount) override;
    void withdraw(double amount) override;
    double getBalance() override;
    void printMiniStatement() override;
    void printFullStatement() override;
};

#endif
