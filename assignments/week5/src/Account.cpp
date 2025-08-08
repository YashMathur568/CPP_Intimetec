#include "Account.h"
#include <ctime>
#include <iostream>
#include <algorithm>

Account::Account() : accountNumber(0), balance(0.0), transactionCount(0) {}

Account::Account(int accNumber) : accountNumber(accNumber), balance(0.0), transactionCount(0) {}

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
    if (transactionCount < MAX_TRANSACTIONS)
    {
        time_t now = time(0);
        std::string dt = ctime(&now);
        transactions[transactionCount++] = Transaction(type, amount, dt);
    }
}

int Account::getTransactionCount()
{
    return transactionCount;
}

void Account::printMiniStatement()
{
    int count = getMiniStatementCount();
    for (int i = std::max(0, transactionCount - count); i < transactionCount; ++i)
    {
        std::cout << transactions[i].getType() << " - "
                  << transactions[i].getAmount() << " - "
                  << transactions[i].getDate();
    }
}

void Account::printFullStatement()
{
    for (int i = 0; i < transactionCount; ++i)
    {
        std::cout << transactions[i].getType() << " - "
                  << transactions[i].getAmount() << " - "
                  << transactions[i].getDate();
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
