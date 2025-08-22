#ifndef MOCKACCOUNT_H
#define MOCKACCOUNT_H

#include "interfaces/IAccount.h"
#include <gmock/gmock.h>

class MockAccount : public IAccount
{
public:
    MOCK_METHOD(void, deposit, (double amount), (override));
    MOCK_METHOD(void, withdraw, (double amount), (override));
    MOCK_METHOD(double, getBalance, (), (override));
    MOCK_METHOD(int, getTransactionCount, (), (override));
    MOCK_METHOD(void, printMiniStatement, (), (override));
    MOCK_METHOD(void, printFullStatement, (), (override));
    MOCK_METHOD(int, getAccountNumber, (), (override));
};

#endif