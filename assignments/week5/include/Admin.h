#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "AccountHolder.h"
#include <string>

class Bank;

class Admin : public User
{
public:
    Admin();
    Admin(int userId, std::string name, int age, std::string email, std::string contactNumber, std::string password);

    bool createAccountForAccountHolder(AccountHolder &accHolder, Bank &bank);
    Account *searchAccountByNumber(int accNumber, Bank &bank);
    void closeAccount(int accNumber, Bank &bank);
};

#endif