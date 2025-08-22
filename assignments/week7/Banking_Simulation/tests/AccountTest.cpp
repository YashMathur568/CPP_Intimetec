#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Account.h"
#include "mocks/MockTimeService.h"

class AccountTest : public ::testing::Test
{
protected:
    Account *account;
    MockTimeService *mockTimeService;

    void SetUp() override
    {
        mockTimeService = new MockTimeService();
        account = new Account(123456, mockTimeService);
    }

    void TearDown() override
    {
        delete account;
        delete mockTimeService;
    }
};

TEST_F(AccountTest, ConstructorInitializesCorrectly)
{
    EXPECT_EQ(account->getAccountNumber(), 123456);
    EXPECT_DOUBLE_EQ(account->getBalance(), 0.0);
    EXPECT_EQ(account->getTransactionCount(), 0);
}

TEST_F(AccountTest, DepositIncreasesBalanceAndCreatesTransaction)
{
    EXPECT_CALL(*mockTimeService, getCurrentTime()).WillOnce(::testing::Return("Mon Jan 01 12:00:00 2024\n"));

    account->deposit(100.0);

    EXPECT_DOUBLE_EQ(account->getBalance(), 100.0);
    EXPECT_EQ(account->getTransactionCount(), 1);
}

TEST_F(AccountTest, MultipleDepositsIncreaseBothBalanceAndTransactionCount)
{
    EXPECT_CALL(*mockTimeService, getCurrentTime()).Times(3).WillRepeatedly(::testing::Return("Mon Jan 01 12:00:00 2024\n"));

    account->deposit(100.0);
    account->deposit(50.0);
    account->deposit(25.0);

    EXPECT_DOUBLE_EQ(account->getBalance(), 175.0);
    EXPECT_EQ(account->getTransactionCount(), 3);
}

TEST_F(AccountTest, WithdrawDecreasesBalanceAndCreatesTransaction)
{
    EXPECT_CALL(*mockTimeService, getCurrentTime()).Times(2).WillRepeatedly(::testing::Return("Mon Jan 01 12:00:00 2024\n"));

    account->deposit(200.0);
    account->withdraw(50.0);

    EXPECT_DOUBLE_EQ(account->getBalance(), 150.0);
    EXPECT_EQ(account->getTransactionCount(), 2);
}

TEST_F(AccountTest, WithdrawExactBalanceAmount)
{
    EXPECT_CALL(*mockTimeService, getCurrentTime())
        .Times(2)
        .WillRepeatedly(::testing::Return("Mon Jan 01 12:00:00 2024\n"));

    account->deposit(100.0);
    account->withdraw(100.0);

    EXPECT_DOUBLE_EQ(account->getBalance(), 0.0);
    EXPECT_EQ(account->getTransactionCount(), 2);
}

TEST_F(AccountTest, WithdrawWithInsufficientFunds)
{
    account->withdraw(100.0);

    EXPECT_DOUBLE_EQ(account->getBalance(), 0.0);
    EXPECT_EQ(account->getTransactionCount(), 0);
}

TEST_F(AccountTest, WithdrawMoreThanBalanceAfterDeposit)
{
    EXPECT_CALL(*mockTimeService, getCurrentTime())
        .WillOnce(::testing::Return("Mon Jan 01 12:00:00 2024\n"));

    account->deposit(50.0);
    account->withdraw(100.0);

    EXPECT_DOUBLE_EQ(account->getBalance(), 50.0);
    EXPECT_EQ(account->getTransactionCount(), 1);
}

TEST_F(AccountTest, GetMiniStatementCountWithFewTransactions)
{
    EXPECT_CALL(*mockTimeService, getCurrentTime())
        .Times(3)
        .WillRepeatedly(::testing::Return("Mon Jan 01 12:00:00 2024\n"));

    account->deposit(100.0);
    account->deposit(50.0);
    account->withdraw(25.0);

    EXPECT_EQ(account->getMiniStatementCount(), 3);
}

TEST_F(AccountTest, GetMiniStatementCountWithManyTransactions)
{
    EXPECT_CALL(*mockTimeService, getCurrentTime())
        .Times(7)
        .WillRepeatedly(::testing::Return("Mon Jan 01 12:00:00 2024\n"));

    for (int i = 0; i < 7; i++)
    {
        account->deposit(10.0);
    }

    EXPECT_EQ(account->getMiniStatementCount(), 5);
}

TEST_F(AccountTest, TransactionArrayResizing)
{
    EXPECT_CALL(*mockTimeService, getCurrentTime())
        .Times(15)
        .WillRepeatedly(::testing::Return("Mon Jan 01 12:00:00 2024\n"));

    for (int i = 0; i < 15; i++)
    {
        account->deposit(10.0);
    }

    EXPECT_EQ(account->getTransactionCount(), 15);
    EXPECT_DOUBLE_EQ(account->getBalance(), 150.0);
}