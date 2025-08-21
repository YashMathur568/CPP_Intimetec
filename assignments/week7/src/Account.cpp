#include "Account.h"
#include "Transaction.h"
#include <ctime>
#include <iostream>

Account::Account(int accNumber)
    : accountNumber(accNumber), balance(0.0), transactionCount(0), transactionCapacity(INITIAL_TRANSACTION_COUNT)
{
    transactions = new Transaction *[transactionCapacity];
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

    TransactionInterface *transaction = new Transaction("Deposit", amount, std::ctime(nullptr));
    addTransaction(transaction);
}

void Account::withdraw(double amount)
{
    if (amount <= balance)
    {
        balance -= amount;
        ITransaction *transaction = new Transaction("Withdraw", amount, std::ctime(nullptr));
        addTransaction(transaction);
    }
    else
    {
        std::cout << "Insufficient balance!" << std::endl;
    }
}

void Account::addTransaction(ITransaction *transaction)
{
    if (transactionCount == transactionCapacity)
    {
        resizeTransactions();
    }

    transactions[transactionCount++] = transaction;
}

void Account::resizeTransactions()
{
    transactionCapacity *= 2;
    ITransaction **newTransactions = new ITransaction *[transactionCapacity];

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

    int miniStatementCount = std::min(transactionCount, 5);
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

double Account::getBalance()
{
    return balance;
}

int Account::getTransactionCount()
{
    return transactionCount;
}

int Account::getAccountNumber() const
{
    return accountNumber;
}
