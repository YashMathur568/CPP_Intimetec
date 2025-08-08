#include "AccountHolder.h"
#include <iostream>

AccountHolder::AccountHolder() {}

AccountHolder::AccountHolder(int userId, std::string name, int age, std::string email, std::string contactNumber, std::string password, int accountNumber)
    : User(userId, name, age, email, contactNumber, password, UserType::AccountHolder),
      account(accountNumber) {}

void AccountHolder::depositToAccount(double amount)
{
    account.deposit(amount);
}

void AccountHolder::withdrawFromAccount(double amount)
{
    account.withdraw(amount);
}

double AccountHolder::checkBalance()
{
    return account.getBalance();
}

void AccountHolder::viewMiniStatement()
{
    account.printMiniStatement();
}

void AccountHolder::viewFullStatement()
{
    account.printFullStatement();
}

Account &AccountHolder::getAccount()
{
    return account;
}
