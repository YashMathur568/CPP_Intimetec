#include "Account.h"

Account::Account(int accNumber) : accountNumber(accNumber), balance(0) {}

void Account::deposit(double amount)
{
    balance += amount;
}

double Account::getBalance() const
{
    return balance;
}

int Account::getAccountNumber() const
{
    return accountNumber;
}
