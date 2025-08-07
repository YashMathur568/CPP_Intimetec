#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Bank.h"
#include "AccountHolder.h"

class Admin : public User
{
private:
    Bank *bankRef;

public:
    Admin(int id, string name, string email, string contactNumber, Bank *bank)
        : User(id, name, email, contactNumber, UserType::Admin), bankRef(bank) {}

    void createAccountForAccountHolder(AccountHolder &accountHolder);
    Account *searchAccountByNumber(int accountNumber);
    void closeAccount(int accountNumber);
};

#endif
