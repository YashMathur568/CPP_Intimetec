#ifndef MOCK_TRANSACTION_H
#define MOCK_TRANSACTION_H

#include "TransactionInterface.h"
#include <gmock/gmock.h>

class MockTransaction : public ITransaction
{
public:
    MOCK_METHOD(std::string, getType, (), (const, override));
    MOCK_METHOD(double, getAmount, (), (const, override));
    MOCK_METHOD(std::string, getDateTime, (), (const, override));
};

#endif
