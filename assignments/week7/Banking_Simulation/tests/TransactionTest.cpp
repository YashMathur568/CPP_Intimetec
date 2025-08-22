#include <gtest/gtest.h>
#include "Transaction.h"

class TransactionTest : public ::testing::Test
{
protected:
    Transaction *transaction;

    void SetUp() override
    {
        transaction = new Transaction("Deposit", 100.50, "Mon Jan 01 12:00:00 2024\n");
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
    EXPECT_EQ(transaction->getDateTime(), "Mon Jan 01 12:00:00 2024\n");
}

TEST_F(TransactionTest, GetterMethodsReturnCorrectValues)
{
    Transaction withdrawTransaction("Withdraw", 50.25, "Mon Jan 01 13:00:00 2024\n");

    EXPECT_EQ(withdrawTransaction.getType(), "Withdraw");
    EXPECT_DOUBLE_EQ(withdrawTransaction.getAmount(), 50.25);
    EXPECT_EQ(withdrawTransaction.getDateTime(), "Mon Jan 01 13:00:00 2024\n");
}

TEST_F(TransactionTest, HandleEmptyStrings)
{
    Transaction emptyTransaction("", 0.0, "");

    EXPECT_EQ(emptyTransaction.getType(), "");
    EXPECT_DOUBLE_EQ(emptyTransaction.getAmount(), 0.0);
    EXPECT_EQ(emptyTransaction.getDateTime(), "");
}

TEST_F(TransactionTest, HandleSpecialCharacters)
{
    Transaction specialTransaction("Dep@sit!", 999.99, "Special\nDate");

    EXPECT_EQ(specialTransaction.getType(), "Dep@sit!");
    EXPECT_DOUBLE_EQ(specialTransaction.getAmount(), 999.99);
    EXPECT_EQ(specialTransaction.getDateTime(), "Special\nDate");
}