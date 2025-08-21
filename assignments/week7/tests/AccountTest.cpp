#include "gtest/gtest.h"
#include "Account.h"
#include "MockTransaction.h"

class AccountTest : public ::testing::Test
{
protected:
    Account *account;

    void SetUp() override
    {
        account = new Account(1001);
    }

    void TearDown() override
    {
        delete account;
    }
};

TEST_F(AccountTest, DepositIncreasesBalance)
{
    account->deposit(1000.0);
    EXPECT_DOUBLE_EQ(account->getBalance(), 1000.0);
}

TEST_F(AccountTest, WithdrawDecreasesBalance)
{
    account->deposit(1000.0);
    account->withdraw(500.0);
    EXPECT_DOUBLE_EQ(account->getBalance(), 500.0);
}

TEST_F(AccountTest, InsufficientBalanceForWithdraw)
{
    account->deposit(1000.0);
    account->withdraw(1500.0);
    EXPECT_DOUBLE_EQ(account->getBalance(), 1000.0);
}

TEST_F(AccountTest, AddTransactionWhenDeposited)
{
    MockTransaction mockTransaction;

    EXPECT_CALL(mockTransaction, getType()).WillOnce(::testing::Return("Deposit"));
    EXPECT_CALL(mockTransaction, getAmount()).WillOnce(::testing::Return(1000.0));
    EXPECT_CALL(mockTransaction, getDateTime()).WillOnce(::testing::Return("TimeStamp"));

    account->deposit(1000.0);
    account->printMiniStatement();
}

TEST_F(AccountTest, AddTransactionWhenWithdrawn)
{
    MockTransaction mockTransaction;

    EXPECT_CALL(mockTransaction, getType()).WillOnce(::testing::Return("Withdraw"));
    EXPECT_CALL(mockTransaction, getAmount()).WillOnce(::testing::Return(500.0));
    EXPECT_CALL(mockTransaction, getDateTime()).WillOnce(::testing::Return("TimeStamp"));

    account->deposit(1000.0);

    account->withdraw(500.0);
    account->printMiniStatement();
}
