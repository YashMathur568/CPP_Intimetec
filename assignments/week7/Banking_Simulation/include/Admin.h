#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "interfaces/IBank.h"

class AccountHolder;
class Account;

class Admin : public User
{
private:
    IBank &bank;

public:
    Admin(int userId, std::string name, int age, std::string email,
          std::string contactNumber, std::string password, IBank &bank);

    bool createAccountForAccountHolder(const AccountHolder &accHolder);
    Account *searchAccountByNumber(int accountNumber);
    void closeAccount(int accountNumber);
};

#endif