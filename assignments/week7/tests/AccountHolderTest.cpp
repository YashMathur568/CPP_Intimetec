#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "AccountHolder.h"
#include "MockAccount.h"

class AccountHolderTest : public ::testing::Test
{
protected:
    MockAccount *mockAccount;
    AccountHolder *accountHolder;

    void SetUp() override
    {
        mockAccount = new MockAccount();
        accountHolder = new AccountHolder(1001, "John Doe", 30, "john.doe@gmail.com", "1234567890", "password123", mockAccount);
    }

    void TearDown() override
    {
        delete accountHolder;
        delete mockAccount;
    }
};

TEST_F(AccountHolderTest, DepositTest)
{
    double depositAmount = 100.0;

    EXPECT_CALL(*mockAccount, deposit(depositAmount))
        .Times(1);

    accountHolder->depositToAccount(depositAmount);
}

TEST_F(AccountHolderTest, WithdrawTest)
{
    double withdrawAmount = 50.0;

    EXPECT_CALL(*mockAccount, withdraw(withdrawAmount))
        .Times(1);

    accountHolder->withdrawFromAccount(withdrawAmount);
}

TEST_F(AccountHolderTest, CheckBalanceTest)
{
    double balance = 200.0;

    EXPECT_CALL(*mockAccount, getBalance())
        .Times(1)
        .WillOnce(testing::Return(balance));

    EXPECT_EQ(accountHolder->checkBalance(), balance);
}
