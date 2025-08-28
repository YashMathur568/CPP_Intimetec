#ifndef IBANK_H
#define IBANK_H

#include <string>
class AccountHolder;
class Account;
class User;

class IBank
{
public:
    virtual bool createAccount(const AccountHolder &accHolder, const User &user) = 0;
    virtual Account *searchAccount(int accountNumber, const User &user) = 0;
    virtual void closeAccount(int accountNumber, const User &user) = 0;
    virtual AccountHolder *loginAccountHolder(int inputUserId, std::string inputPassword) = 0;
    virtual int generateUniqueUserId() = 0;
    virtual int generateUniqueAccountNumber() = 0;
    virtual ~IBank() = default;
};

#endif