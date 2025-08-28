#include "Account.h"
#include "TimeService.h"
#include <iostream>

Account::Account(int accNumber, ITimeService *timeService)
    : accountNumber(accNumber), balance(0.0), transactionCount(0),
      transactionCapacity(INITIAL_TRANSACTION_COUNT), timeService(timeService)
{
    transactions = new Transaction *[transactionCapacity];

    if (this->timeService == nullptr)
    {
        this->timeService = new TimeService();
        ownsTimeService = true;
    }
    else
    {
        ownsTimeService = false;
    }
}

Account::~Account()
{
    for (int transactionIndex = 0; transactionIndex < transactionCount; transactionIndex++)
    {
        delete transactions[transactionIndex];
    }
    delete[] transactions;

    if (ownsTimeService)
    {
        delete timeService;
    }
}

void Account::deposit(double amount)
{
    balance += amount;
    addTransaction("Deposit", amount);
}

void Account::withdraw(double amount)
{
    if (amount <= balance)
    {
        balance -= amount;
        addTransaction("Withdraw", amount);
    }
    else
    {
        std::cout << "Insufficient balance!" << std::endl;
    }
}

void Account::addTransaction(std::string type, double amount)
{
    if (transactionCount == transactionCapacity)
    {
        resizeTransactions();
    }

    std::string transactionTime = timeService->getCurrentTime();
    transactions[transactionCount++] = new Transaction(type, amount, transactionTime);
}

double Account::getBalance()
{
    return balance;
}

int Account::getTransactionCount()
{
    return transactionCount;
}

void Account::resizeTransactions()
{
    transactionCapacity *= 2;
    Transaction **newTransactions = new Transaction *[transactionCapacity];

    for (int transactionIndex = 0; transactionIndex < transactionCount; transactionIndex++)
    {
        newTransactions[transactionIndex] = transactions[transactionIndex];
    }

    delete[] transactions;
    transactions = newTransactions;
}

void Account::printMiniStatement()
{
    if (transactionCount == 0)
    {
        std::cout << "No transactions found.\n";
        return;
    }

    int miniStatementCount = getMiniStatementCount();
    for (int transactionIndex = std::max(0, transactionCount - miniStatementCount);
         transactionIndex < transactionCount; transactionIndex++)
    {
        std::cout << transactions[transactionIndex]->getType() << " "
                  << transactions[transactionIndex]->getAmount() << " - "
                  << transactions[transactionIndex]->getDateTime();
    }
}

void Account::printFullStatement()
{
    if (transactionCount == 0)
    {
        std::cout << "No transactions found.\n";
        return;
    }

    std::cout << "Showing all transactions:\n";

    for (int transactionIndex = 0; transactionIndex < transactionCount; transactionIndex++)
    {
        std::cout << transactions[transactionIndex]->getType() << " "
                  << transactions[transactionIndex]->getAmount() << " - "
                  << transactions[transactionIndex]->getDateTime();
    }
}

int Account::getMiniStatementCount()
{
    return std::min(transactionCount, 5);
}

int Account::getAccountNumber()
{
    return accountNumber;
}

int Account::getTransactionCapacity()
{
    return transactionCapacity;
}

void Account::setBalance(double newBalance)
{
    balance = newBalance;
}
