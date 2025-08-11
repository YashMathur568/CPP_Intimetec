#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "AccountHolder.h"

class Bank;

class Admin : public User
{
public:
    Admin(int userId, std::string name, int age, std::string email, std::string contactNumber, std::string password);

    bool createAccountForAccountHolder(const AccountHolder &accHolder, Bank &bank);
    Account *searchAccountByNumber(int accNumber, Bank &bank);
    void closeAccount(int accNumber, Bank &bank);
};

#endif