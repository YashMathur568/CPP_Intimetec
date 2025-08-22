#include "Admin.h"

Admin::Admin(int userId, std::string name, int age, std::string email,
             std::string contactNumber, std::string password, IBank *bank)
    : User(userId, name, age, email, contactNumber, password, UserType::Admin), bank(bank) {}

bool Admin::createAccountForAccountHolder(const AccountHolder &accHolder, IBank &bank)
{
    return bank.createAccount(accHolder, *this);
}

Account *Admin::searchAccountByNumber(int accountNumber, IBank &bank)
{
    return bank.searchAccount(accountNumber, *this);
}

void Admin::closeAccount(int accountNumber, IBank &bank)
{
    bank.closeAccount(accountNumber, *this);
}

bool Admin::createAccountForAccountHolder(const AccountHolder &accHolder)
{
    if (bank)
    {
        return bank->createAccount(accHolder, *this);
    }
    return false;
}

Account *Admin::searchAccountByNumber(int accountNumber)
{
    if (bank)
    {
        return bank->searchAccount(accountNumber, *this);
    }
    return nullptr;
}

void Admin::closeAccount(int accountNumber)
{
    if (bank)
    {
        bank->closeAccount(accountNumber, *this);
    }
}