#ifndef MOCKBANK_H
#define MOCKBANK_H

#include "interfaces/IBank.h"
#include <gmock/gmock.h>

class MockBank : public IBank
{
public:
    MOCK_METHOD(bool, createAccount, (const AccountHolder &accHolder, const User &user), (override));
    MOCK_METHOD(Account *, searchAccount, (int accountNumber, const User &user), (override));
    MOCK_METHOD(void, closeAccount, (int accountNumber, const User &user), (override));
    MOCK_METHOD(AccountHolder *, loginAccountHolder, (int inputUserId, std::string inputPassword), (override));
    MOCK_METHOD(int, generateUniqueUserId, (), (override));
    MOCK_METHOD(int, generateUniqueAccountNumber, (), (override));
};

#endif