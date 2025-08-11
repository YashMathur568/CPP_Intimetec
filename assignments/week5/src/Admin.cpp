#include "Admin.h"
#include "Bank.h"
#include <iostream>

Admin::Admin() {}

Admin::Admin(int userId, std::string name, int age, std::string email, std::string contactNumber, std::string password)
    : User(userId, name, age, email, contactNumber, password, UserType::Admin) {}

bool Admin::createAccountForAccountHolder(const AccountHolder &accHolder, Bank &bank)
{
    return bank.createAccount(accHolder, *this);
}

Account *Admin::searchAccountByNumber(int accountNumber, Bank &bank)
{
    return bank.searchAccount(accountNumber, *this);
}

void Admin::closeAccount(int accountNumber, Bank &bank)
{
    bank.closeAccount(accountNumber, *this);
}