#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transaction.h"
#include "interfaces/ITimeService.h"
#include "interfaces/IAccount.h"
#include <string>

#define INITIAL_TRANSACTION_COUNT 10

class Account : public IAccount
{
private:
    int accountNumber;
    double balance;
    Transaction **transactions;
    int transactionCount;
    int transactionCapacity;
    ITimeService *timeService;
    bool ownsTimeService;

    void addTransaction(std::string type, double amount);

public:
    Account(int accNumber, ITimeService *timeService = nullptr);
    ~Account();

    void deposit(double amount) override;
    void withdraw(double amount) override;
    double getBalance() override;
    int getTransactionCount() override;
    void resizeTransactions();
    void printMiniStatement() override;
    void printFullStatement() override;
    int getMiniStatementCount();
    int getAccountNumber() override;

    int getTransactionCapacity();
    void setBalance(double newBalance);
};

#endif
