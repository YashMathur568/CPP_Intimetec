#ifndef ACCOUNTHOLDER_H
#define ACCOUNTHOLDER_H

#include "User.h"
#include "interfaces/IAccount.h"

class AccountHolder : public User
{
private:
    IAccount *account;
    bool ownsAccount;

public:
    AccountHolder(int userId, std::string name, int age, std::string email,
                  std::string contactNumber, std::string password, int accountNumber,
                  IAccount *account = nullptr);
    AccountHolder(const AccountHolder &other);
    ~AccountHolder();

    void depositToAccount(double amount);
    void withdrawFromAccount(double amount);
    double checkBalance();
    void viewMiniStatement();
    void viewFullStatement();
    IAccount &getAccount();

    int getUserId() { return User::getUserId(); }
    std::string getName() { return User::getName(); }
    UserType getUserType() { return User::getUserType(); }
    bool authenticate(int userId, std::string password) { return User::authenticate(userId, password); }
};

#endif
