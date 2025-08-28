#include "Admin.h"

Admin::Admin(int userId, std::string name, int age, std::string email,
             std::string contactNumber, std::string password, IBank &bank)
    : User(userId, name, age, email, contactNumber, password, UserType::Admin), bank(bank) {}

bool Admin::createAccountForAccountHolder(const AccountHolder &accHolder)
{
    return bank.createAccount(accHolder, *this);
}

Account *Admin::searchAccountByNumber(int accountNumber)
{
    return bank.searchAccount(accountNumber, *this);
}

void Admin::closeAccount(int accountNumber)
{
    bank.closeAccount(accountNumber, *this);
}