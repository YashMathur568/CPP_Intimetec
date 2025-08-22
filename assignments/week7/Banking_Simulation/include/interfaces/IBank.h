#ifndef IBANK_H
#define IBANK_H

class AccountHolder;
class Admin;
class Account;

class IBank
{
public:
    virtual bool createAccount(const AccountHolder &accHolder, Admin &admin) = 0;
    virtual Account *searchAccount(int accountNumber, Admin &admin) = 0;
    virtual void closeAccount(int accountNumber, Admin &admin) = 0;
    virtual AccountHolder *loginAccountHolder(int inputUserId, std::string inputPassword) = 0;
    virtual int generateUniqueUserId() = 0;
    virtual int generateUniqueAccountNumber() = 0;
    virtual ~IBank() = default;
};

#endif