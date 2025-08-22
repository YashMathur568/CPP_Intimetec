#ifndef ACCOUNTHOLDER_H
#define ACCOUNTHOLDER_H

#include "User.h"
#include "interfaces/IAccount.h"
#include "interfaces/IAccountHolder.h"

class AccountHolder : public User, public IAccountHolder
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

    void depositToAccount(double amount) override;
    void withdrawFromAccount(double amount) override;
    double checkBalance() override;
    void viewMiniStatement() override;
    void viewFullStatement() override;
    IAccount &getAccount() override;

    int getUserId() override { return User::getUserId(); }
    std::string getName() override { return User::getName(); }
    UserType getUserType() override { return User::getUserType(); }
    bool authenticate(int userId, std::string password) override { return User::authenticate(userId, password); }
};

#endif
