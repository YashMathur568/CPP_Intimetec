#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transaction.h"
#include <iostream>
using namespace std;

class Account
{
private:
    int accountNumber;
    double balance;
    Transaction *transactions[10];
    int transactionCount;

public:
    Account() : accountNumber(0), balance(0.0), transactionCount(0) {}

    Account(int accNum) : accountNumber(accNum), balance(0.0), transactionCount(0) {}

    int getAccountNumber()
    {
        return accountNumber;
    }
    double getBalance()
    {
        return balance;
    }
    int getTransactionCount()
    {
        return transactionCount;
    }

    void deposit(double amount);
    void withdraw(double amount);
    void addTransaction(const string &type, double amount);
    void viewMiniStatement();
    void viewFullStatement();

    void setAccountNumber(int accNum) { accountNumber = accNum; }
    void setBalance(double bal)
    {
        balance = bal;
    }
};

#endif
