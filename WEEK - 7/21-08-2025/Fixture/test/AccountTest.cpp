#include <gtest/gtest.h>
#include "Account.h"

class AccountTest : public ::testing::Test
{
protected:
    Account *account;

    void SetUp() override
    {
        account = new Account(1982);
    }

    void TearDown() override
    {
        delete account;
    }
};

TEST_F(AccountTest, DepositIncreasesBalance)
{
    account->deposit(100);
    EXPECT_EQ(account->getBalance(), 100);
}

TEST_F(AccountTest, MultipleDeposits)
{
    account->deposit(100);
    account->deposit(50);
    EXPECT_EQ(account->getBalance(), 150);
}

TEST_F(AccountTest, AccountNumber)
{
    EXPECT_EQ(account->getAccountNumber(), 1982);
}
