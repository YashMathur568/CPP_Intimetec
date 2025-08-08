#include "Admin.h"
#include "Bank.h"

Admin::Admin() {}

Admin::Admin(int userId, std::string name, int age, std::string email, std::string contactNumber, std::string password)
    : User(userId, name, age, email, contactNumber, password, UserType::Admin) {}

bool Admin::createAccountForAccountHolder(AccountHolder &accHolder, Bank &bank)
{
    return bank.createAccount(accHolder, *this);
}

Account *Admin::searchAccountByNumber(int accNumber, Bank &bank)
{
    return bank.searchAccount(accNumber, *this);
}

void Admin::closeAccount(int accNumber, Bank &bank)
{
    bank.closeAccount(accNumber, *this);
}
