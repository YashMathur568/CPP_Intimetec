#include <gtest/gtest.h>
#include "Transaction.h"

class TransactionTest : public ::testing::Test
{
protected:
    Transaction *transaction;

    void SetUp() override
    {
        transaction = new Transaction("Deposit", 100.50, "Tue Apr 19 13:00:00 2025\n");
    }

    void TearDown() override
    {
        delete transaction;
    }
};

TEST_F(TransactionTest, ConstructorInitializesAllFields)
{
    EXPECT_EQ(transaction->getType(), "Deposit");
    EXPECT_DOUBLE_EQ(transaction->getAmount(), 100.50);
    EXPECT_EQ(transaction->getDateTime(), "Tue Apr 19 13:00:00 2025\n");
}

TEST_F(TransactionTest, GetterMethodsReturnCorrectValues)
{
    Transaction withdrawTransaction("Withdraw", 50.25, "Tue Apr 19 13:00:00 2025\n");

    EXPECT_EQ(withdrawTransaction.getType(), "Withdraw");
    EXPECT_DOUBLE_EQ(withdrawTransaction.getAmount(), 50.25);
    EXPECT_EQ(withdrawTransaction.getDateTime(), "Tue Apr 19 13:00:00 2025\n");
}

TEST_F(TransactionTest, HandleEmptyStrings)
{
    Transaction emptyTransaction("", 0.0, "");

    EXPECT_EQ(emptyTransaction.getType(), "");
    EXPECT_DOUBLE_EQ(emptyTransaction.getAmount(), 0.0);
    EXPECT_EQ(emptyTransaction.getDateTime(), "");
}