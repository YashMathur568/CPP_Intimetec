#ifndef ACCOUNTHOLDER_H
#define ACCOUNTHOLDER_H

#include "User.h"
#include "Account.h"
#include <string>

class AccountHolder : public User
{
    Account account;

public:
    AccountHolder();
    AccountHolder(int userId, std::string name, int age, std::string email, std::string contactNumber, std::string password, int accountNumber);

    void depositToAccount(double amount);
    void withdrawFromAccount(double amount);
    double checkBalance();
    void viewMiniStatement();
    void viewFullStatement();
    Account &getAccount();
};

#endif
