#include "Account.h"
#include <ctime>
#include <iostream>

Account::Account(int accNumber)
    : accountNumber(accNumber), balance(0.0), transactionCount(0), transactionCapacity(INITIAL_TRANSACTION_COUNT)
{
    transactions = new Transaction *[transactionCapacity];
}

Account::Account(const Account &other)
    : accountNumber(other.accountNumber),
      balance(other.balance),
      transactionCount(other.transactionCount),
      transactionCapacity(other.transactionCapacity)
{
    transactions = new Transaction *[transactionCapacity];

    for (int transactionIndex = 0; transactionIndex < transactionCount; transactionIndex++)
    {
        transactions[transactionIndex] = new Transaction(
            other.transactions[transactionIndex]->getType(),
            other.transactions[transactionIndex]->getAmount(),
            other.transactions[transactionIndex]->getDateTime());
    }
}

Account::~Account()
{
    for (int transactionIndex = 0; transactionIndex < transactionCount; transactionIndex++)
    {
        delete transactions[transactionIndex];
    }
    delete[] transactions;
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

double Account::getBalance()
{
    return balance;
}

void Account::addTransaction(std::string type, double amount)
{
    if (transactionCount == transactionCapacity)
    {
        resizeTransactions();
    }

    std::time_t currentTime = std::time(0);
    std::string transactionTime = std::ctime(&currentTime);
    transactions[transactionCount++] = new Transaction(type, amount, transactionTime);
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
    for (int transactionIndex = std::max(0, transactionCount - miniStatementCount); transactionIndex < transactionCount; transactionIndex++)
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