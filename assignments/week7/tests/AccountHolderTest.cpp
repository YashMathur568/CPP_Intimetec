#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "AccountHolder.h"
#include "mocks/MockAccount.h"

class AccountHolderTest : public ::testing::Test
{
protected:
    AccountHolder *accountHolder;
    MockAccount *mockAccount;

    void SetUp() override
    {
        mockAccount = new MockAccount();
        accountHolder = new AccountHolder(12345, "Ramesh", 30, "ramesh@test.com",
                                          "1234567890", "password123", 654321, mockAccount);
    }

    void TearDown() override
    {
        delete accountHolder;
        delete mockAccount;
    }
};

TEST_F(AccountHolderTest, ConstructorInitializesUserFieldsCorrectly)
{
    EXPECT_EQ(accountHolder->getUserId(), 12345);
    EXPECT_EQ(accountHolder->getName(), "Ramesh");
    EXPECT_EQ(accountHolder->getAge(), 30);
    EXPECT_EQ(accountHolder->getEmail(), "ramesh@test.com");
    EXPECT_EQ(accountHolder->getContactNumber(), "1234567890");
    EXPECT_EQ(accountHolder->getUserType(), UserType::AccountHolder);
}

TEST_F(AccountHolderTest, DepositDelegatesToAccount)
{
    EXPECT_CALL(*mockAccount, deposit(100.0))
        .Times(1);

    accountHolder->depositToAccount(100.0);
}

TEST_F(AccountHolderTest, WithdrawDelegatesToAccount)
{
    EXPECT_CALL(*mockAccount, withdraw(50.0))
        .Times(1);

    accountHolder->withdrawFromAccount(50.0);
}

TEST_F(AccountHolderTest, CheckBalanceDelegatesToAccount)
{
    EXPECT_CALL(*mockAccount, getBalance())
        .WillOnce(::testing::Return(150.0));

    double balance = accountHolder->checkBalance();
    EXPECT_DOUBLE_EQ(balance, 150.0);
}

TEST_F(AccountHolderTest, ViewMiniStatementDelegatesToAccount)
{
    EXPECT_CALL(*mockAccount, printMiniStatement())
        .Times(1);

    accountHolder->viewMiniStatement();
}

TEST_F(AccountHolderTest, ViewFullStatementDelegatesToAccount)
{
    EXPECT_CALL(*mockAccount, printFullStatement())
        .Times(1);

    accountHolder->viewFullStatement();
}

TEST_F(AccountHolderTest, GetAccountReturnsCorrectReference)
{
    IAccount &account = accountHolder->getAccount();
    EXPECT_EQ(&account, mockAccount);
}

TEST_F(AccountHolderTest, AuthenticationWorks)
{
    EXPECT_TRUE(accountHolder->authenticate(12345, "password123"));
    EXPECT_FALSE(accountHolder->authenticate(12345, "wrongpass"));
    EXPECT_FALSE(accountHolder->authenticate(54321, "password123"));
}