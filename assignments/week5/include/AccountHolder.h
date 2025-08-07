#ifndef ACCOUNTHOLDER_H
#define ACCOUNTHOLDER_H

#include "User.h"
#include "Account.h"

class AccountHolder : public User
{
private:
    Account account;

public:
    AccountHolder() {};
    AccountHolder(int id, string name, string email, string contactNumber)
        : User(id, name, email, contactNumber, UserType::AccountHolder), account() {}

    void depositMoney(double amount);
    void withdrawMoney(double amount);
    void viewMiniStatement();
    void viewFullStatement();
};

#endif
