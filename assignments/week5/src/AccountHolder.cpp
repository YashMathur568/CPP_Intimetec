#include "AccountHolder.h"
#include <iostream>

AccountHolder::AccountHolder(int userId, std::string name, int age, std::string email, std::string contactNumber, std::string password, int accountNumber)
    : User(userId, name, age, email, contactNumber, password, UserType::AccountHolder)
{
    account = new Account(accountNumber);
}

AccountHolder::AccountHolder(const AccountHolder &other)
    : User(other.userId, other.name, other.age, other.email, other.contactNumber, other.password, other.userType)
{
    if (other.account != nullptr)
    {
        account = new Account(other.account->getAccountNumber());
    }
    else
    {
        account = nullptr;
    }
}

AccountHolder::~AccountHolder()
{
    delete account;
}

void AccountHolder::depositToAccount(double amount)
{
    if (account)
    {
        account->deposit(amount);
    }
}

void AccountHolder::withdrawFromAccount(double amount)
{
    if (account)
    {
        account->withdraw(amount);
    }
}

double AccountHolder::checkBalance()
{
    if (account)
    {
        return account->getBalance();
    }
    return 0.0;
}

void AccountHolder::viewMiniStatement()
{
    if (account)
    {
        account->printMiniStatement();
    }
}

void AccountHolder::viewFullStatement()
{
    if (account)
    {
        account->printFullStatement();
    }
}

Account &AccountHolder::getAccount()
{
    return *account;
}