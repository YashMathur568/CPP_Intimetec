#ifndef ACCOUNTHOLDER_H
#define ACCOUNTHOLDER_H

#include "User.h"
#include "AccountInterface.h"

class AccountHolder : public User
{
private:
    AccountInterface *account;

public:
    AccountHolder(int userId, std::string name, int age, std::string email, std::string contactNumber, std::string password, AccountInterface *account);
    ~AccountHolder();

    void depositToAccount(double amount);
    void withdrawFromAccount(double amount);
    double checkBalance();
    void viewMiniStatement();
    void viewFullStatement();
    AccountInterface *getAccount();
};

#endif
