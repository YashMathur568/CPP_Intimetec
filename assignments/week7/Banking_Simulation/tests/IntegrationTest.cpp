#include <gtest/gtest.h>
#include "Bank.h"
#include "Admin.h"
#include "AccountHolder.h"
#include "Account.h"

class IntegrationTest : public ::testing::Test
{
protected:
    Bank *bank;
    Admin *admin;

    void SetUp() override
    {
        bank = new Bank();
        admin = new Admin(100001, "Admin", 35, "admin@bank.com", "9876543210", "adminpass", *bank);
    }

    void TearDown() override
    {
        delete bank;
        delete admin;
    }
};

TEST_F(IntegrationTest, CompleteAccountLifecycle)
{
    AccountHolder holder(12345, "Tanish Anand", 30, "Tanish@gmail.com", "1234567890", "password123", 654321);

    bool created = bank->createAccount(holder, *admin);
    EXPECT_TRUE(created);

    AccountHolder *loggedIn = bank->loginAccountHolder(12345, "password123");
    EXPECT_NE(loggedIn, nullptr);

    loggedIn->depositToAccount(1000.0);
    EXPECT_DOUBLE_EQ(loggedIn->checkBalance(), 1000.0);

    loggedIn->withdrawFromAccount(300.0);
    EXPECT_DOUBLE_EQ(loggedIn->checkBalance(), 700.0);

    EXPECT_EQ(loggedIn->getAccount().getTransactionCount(), 2);

    Account *foundAccount = bank->searchAccount(654321, *admin);
    EXPECT_NE(foundAccount, nullptr);
    EXPECT_DOUBLE_EQ(foundAccount->getBalance(), 700.0);

    bank->closeAccount(654321, *admin);

    Account *closedAccount = bank->searchAccount(654321, *admin);
    EXPECT_EQ(closedAccount, nullptr);
}

TEST_F(IntegrationTest, MultipleUsersWorkflow)
{
    AccountHolder user1(1001, "Ram", 28, "ram@example.com", "1111111111", "pass1", 600001);
    AccountHolder user2(1002, "Shyam", 32, "shyam@example.com", "2222222222", "pass2", 600002);
    AccountHolder user3(1003, "Bhavesh", 45, "bhavesh@example.com", "3333333333", "pass3", 600003);

    EXPECT_TRUE(bank->createAccount(user1, *admin));
    EXPECT_TRUE(bank->createAccount(user2, *admin));
    EXPECT_TRUE(bank->createAccount(user3, *admin));

    AccountHolder *Ram = bank->loginAccountHolder(1001, "pass1");
    AccountHolder *Shyam = bank->loginAccountHolder(1002, "pass2");
    AccountHolder *Bhavesh = bank->loginAccountHolder(1003, "pass3");
    EXPECT_NE(Ram, nullptr);
    EXPECT_NE(Shyam, nullptr);
    EXPECT_NE(Bhavesh, nullptr);

    Ram->depositToAccount(500.0);
    Shyam->depositToAccount(750.0);
    Bhavesh->depositToAccount(1000.0);

    Ram->withdrawFromAccount(100.0);
    Shyam->withdrawFromAccount(250.0);

    EXPECT_DOUBLE_EQ(Ram->checkBalance(), 400.0);
    EXPECT_DOUBLE_EQ(Shyam->checkBalance(), 500.0);
    EXPECT_DOUBLE_EQ(Bhavesh->checkBalance(), 1000.0);

    EXPECT_EQ(Ram->getAccount().getTransactionCount(), 2);
    EXPECT_EQ(Shyam->getAccount().getTransactionCount(), 2);
    EXPECT_EQ(Bhavesh->getAccount().getTransactionCount(), 1);
}