#include "AccountHolder.h"
#include "Account.h"
#include <iostream>

AccountHolder::AccountHolder(int userId, std::string name, int age, std::string email,
                             std::string contactNumber, std::string password, int accountNumber,
                             IAccount *account)
    : User(userId, name, age, email, contactNumber, password, UserType::AccountHolder),
      account(account)
{
    if (this->account == nullptr)
    {
        this->account = new Account(accountNumber);
        ownsAccount = true;
    }
    else
    {
        ownsAccount = false;
    }
}

AccountHolder::AccountHolder(const AccountHolder &other)
    : User(other.userId, other.name, other.age, other.email, other.contactNumber, other.password, other.userType)
{
    if (other.account != nullptr && other.ownsAccount)
    {
        account = new Account(other.account->getAccountNumber());
        ownsAccount = true;
    }
    else
    {
        account = other.account;
        ownsAccount = false;
    }
}

AccountHolder::~AccountHolder()
{
    if (ownsAccount && account)
    {
        delete account;
    }
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

IAccount &AccountHolder::getAccount()
{
    return *account;
}
