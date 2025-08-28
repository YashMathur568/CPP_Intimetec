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

TEST_F(AccountTest, ConstructorInitializesAccountCorrectly)
{
    EXPECT_EQ(account->getAccountNumber(), 123456);
    EXPECT_DOUBLE_EQ(account->getBalance(), 0.0);
    EXPECT_EQ(account->getTransactionCount(), 0);
}

TEST_F(AccountTest, DepositIncreasesBalanceAndCreatesTransaction)
{
    EXPECT_CALL(*mockTimeService, getCurrentTime()).WillOnce(::testing::Return("Tue Apr 19 13:00:00 2025\n"));

    account->deposit(100.0);

    EXPECT_DOUBLE_EQ(account->getBalance(), 100.0);
    EXPECT_EQ(account->getTransactionCount(), 1);
}

TEST_F(AccountTest, MultipleDepositsIncreaseBothBalanceAndTransactionCount)
{
    EXPECT_CALL(*mockTimeService, getCurrentTime()).Times(3).WillRepeatedly(::testing::Return("Tue Apr 19 13:00:00 2025\n"));

    account->deposit(100.0);
    account->deposit(50.0);
    account->deposit(25.0);

    EXPECT_DOUBLE_EQ(account->getBalance(), 175.0);
    EXPECT_EQ(account->getTransactionCount(), 3);
}

TEST_F(AccountTest, WithdrawDecreasesBalanceAndCreatesTransaction)
{
    EXPECT_CALL(*mockTimeService, getCurrentTime()).Times(2).WillRepeatedly(::testing::Return("Tue Apr 19 13:00:00 2025\n"));

    account->deposit(200.0);
    account->withdraw(50.0);

    EXPECT_DOUBLE_EQ(account->getBalance(), 150.0);
    EXPECT_EQ(account->getTransactionCount(), 2);
}

TEST_F(AccountTest, WithdrawExactBalanceAmount)
{
    EXPECT_CALL(*mockTimeService, getCurrentTime())
        .Times(2)
        .WillRepeatedly(::testing::Return("Tue Apr 19 13:00:00 2025\n"));

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
        .WillOnce(::testing::Return("Tue Apr 19 13:00:00 2025\n"));

    account->deposit(50.0);
    account->withdraw(100.0);

    EXPECT_DOUBLE_EQ(account->getBalance(), 50.0);
    EXPECT_EQ(account->getTransactionCount(), 1);
}

TEST_F(AccountTest, GetMiniStatementCountWithFewTransactions)
{
    EXPECT_CALL(*mockTimeService, getCurrentTime())
        .Times(3)
        .WillRepeatedly(::testing::Return("Tue Apr 19 13:00:00 2025\n"));

    account->deposit(100.0);
    account->deposit(50.0);
    account->withdraw(25.0);

    EXPECT_EQ(account->getMiniStatementCount(), 3);
}

TEST_F(AccountTest, GetMiniStatementCountWithManyTransactions)
{
    EXPECT_CALL(*mockTimeService, getCurrentTime())
        .Times(7)
        .WillRepeatedly(::testing::Return("Tue Apr 19 13:00:00 2025\n"));

    for (int i = 0; i < 7; i++)
    {
        account->deposit(10.0);
    }

    EXPECT_EQ(account->getMiniStatementCount(), 5);
}

TEST_F(AccountTest, TransactionArrayResizing)
{
    EXPECT_EQ(account->getTransactionCapacity(), 10);

    EXPECT_CALL(*mockTimeService, getCurrentTime())
        .Times(10)
        .WillRepeatedly(::testing::Return("Tue Apr 19 13:00:00 2025\n"));

    for (int i = 0; i < 10; i++)
    {
        account->deposit(10.0);
    }

    EXPECT_EQ(account->getTransactionCount(), 10);
    EXPECT_EQ(account->getTransactionCapacity(), 10);

    EXPECT_CALL(*mockTimeService, getCurrentTime())
        .WillOnce(::testing::Return("Tue Apr 19 13:00:00 2025\n"));

    account->deposit(10.0);

    EXPECT_EQ(account->getTransactionCount(), 11);
    EXPECT_EQ(account->getTransactionCapacity(), 20);
    EXPECT_DOUBLE_EQ(account->getBalance(), 110.0);

    EXPECT_CALL(*mockTimeService, getCurrentTime())
        .Times(9)
        .WillRepeatedly(::testing::Return("Tue Apr 19 13:00:00 2025\n"));

    for (int i = 0; i < 9; i++)
    {
        account->deposit(10.0);
    }

    EXPECT_EQ(account->getTransactionCount(), 20);
    EXPECT_EQ(account->getTransactionCapacity(), 20);

    EXPECT_CALL(*mockTimeService, getCurrentTime())
        .WillOnce(::testing::Return("Tue Apr 19 13:00:00 2025\n"));

    account->deposit(10.0);

    EXPECT_EQ(account->getTransactionCount(), 21);
    EXPECT_EQ(account->getTransactionCapacity(), 40);
    EXPECT_DOUBLE_EQ(account->getBalance(), 210.0);
}