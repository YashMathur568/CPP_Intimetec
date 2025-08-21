#include <gtest/gtest.h>
#include "Transaction.h"
#include <ctime>

TEST(TransactionTest, ConstructorAndGetters)
{
    std::string transactionType = "Deposit";
    double amount = 1000.0;

    std::time_t currentTime = std::time(0);
    std::string datetime = std::ctime(&currentTime);

    Transaction transaction(transactionType, amount, datetime);

    EXPECT_EQ(transaction.getType(), transactionType);
    EXPECT_EQ(transaction.getAmount(), amount);
    EXPECT_EQ(transaction.getDateTime(), datetime);
}
