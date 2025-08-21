#ifndef MOCKBANK_H
#define MOCKBANK_H

#include "gmock/gmock.h"
#include "Account.h"
#include "BankInterface.h"

class MockBank : public BankInterface
{
public:
    MOCK_METHOD(bool, createAccount, (const AccountHolder &accHolder, Admin &admin), (override));
    MOCK_METHOD(Account *, searchAccount, (int accountNumber, Admin &admin), (override));
    MOCK_METHOD(void, closeAccount, (int accountNumber, Admin &admin), (override));
    MOCK_METHOD(AccountHolder *, loginAccountHolder, (int inputUserId, std::string inputPassword), (override));
    MOCK_METHOD(int, generateUniqueUserId, (), (override));
    MOCK_METHOD(int, generateUniqueAccountNumber, (), (override));
    MOCK_METHOD(void, resizeAccountHolders, (), (override));
};

#endif
