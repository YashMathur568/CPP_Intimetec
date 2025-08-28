#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transaction.h"
#include <string>

#define INITIAL_TRANSACTION_COUNT 10

class Account
{
    int accountNumber;
    double balance;
    Transaction **transactions;
    int transactionCount;
    int transactionCapacity;
    void addTransaction(std::string type, double amount);

public:
    Account(int accNumber);

    ~Account();

    void deposit(double amount);
    void withdraw(double amount);
    double getBalance();

    int getTransactionCount();
    void resizeTransactions();

    void printMiniStatement();
    void printFullStatement();
    int getMiniStatementCount();
    int getAccountNumber();
};

#endif