#ifndef MOCKACCOUNTHOLDER_H
#define MOCKACCOUNTHOLDER_H

#include "interfaces/IAccountHolder.h"
#include <gmock/gmock.h>

class MockAccountHolder : public IAccountHolder
{
public:
    MOCK_METHOD(int, getUserId, (), (override));
    MOCK_METHOD(std::string, getName, (), (override));
    MOCK_METHOD(UserType, getUserType, (), (override));
    MOCK_METHOD(bool, authenticate, (int userId, std::string password), (override));
    MOCK_METHOD(IAccount &, getAccount, (), (override));
    MOCK_METHOD(void, depositToAccount, (double amount), (override));
    MOCK_METHOD(void, withdrawFromAccount, (double amount), (override));
    MOCK_METHOD(double, checkBalance, (), (override));
    MOCK_METHOD(void, viewMiniStatement, (), (override));
    MOCK_METHOD(void, viewFullStatement, (), (override));
};

#endif
