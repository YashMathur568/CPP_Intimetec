#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transaction.h"
#include <string>

#define MAX_TRANSACTIONS 1000

class Account
{
    int accountNumber;
    double balance;
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;

public:
    Account();
    Account(int accNumber);

    void deposit(double amount);
    void withdraw(double amount);
    double getBalance();
    void addTransaction(std::string type, double amount);

    int getTransactionCount();

    void printMiniStatement();
    void printFullStatement();
    int getMiniStatementCount();
    int getAccountNumber();
};

#endif