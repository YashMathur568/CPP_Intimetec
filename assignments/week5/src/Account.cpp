#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

void Account::deposit(double amount)
{
    balance += amount;
    addTransaction("Deposit", amount);
}

void Account::withdraw(double amount)
{
    if (balance >= amount)
    {
        balance -= amount;
        addTransaction("Withdraw", amount);
    }
    else
    {
        cout << "Insufficient funds!" << endl;
    }
}

void Account::addTransaction(const string &type, double amount)
{
    if (transactionCount < 10)
    {
        transactions[transactionCount++] = new Transaction(type, amount, "2025-08-06");
    }
}

void Account::viewMiniStatement()
{
    cout << "Mini Statement for Account: " << accountNumber << endl;
    for (int i = 0; i < transactionCount; ++i)
    {
        cout << transactions[i]->type << ": " << transactions[i]->amount << endl;
    }
}

void Account::viewFullStatement()
{
    cout << "Full Statement for Account: " << accountNumber << endl;
    for (int i = 0; i < transactionCount; ++i)
    {
        cout << "Type: " << transactions[i]->type << ", Amount: " << transactions[i]->amount << ", Date: " << transactions[i]->date << endl;
    }
}
