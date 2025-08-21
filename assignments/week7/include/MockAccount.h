#ifndef MOCKACCOUNT_H
#define MOCKACCOUNT_H

#include "gmock/gmock.h"
#include "AccountInterface.h"

class MockAccount : public AccountInterface
{
public:
    MOCK_METHOD(void, deposit, (double amount), (override));
    MOCK_METHOD(void, withdraw, (double amount), (override));
    MOCK_METHOD(double, getBalance, (), (override));
    MOCK_METHOD(void, printMiniStatement, (), (override));
    MOCK_METHOD(void, printFullStatement, (), (override));
};

#endif
