#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Admin.h"
#include "Bank.h"
#include "AccountHolder.h"
#include "Account.h"

class BankTest : public ::testing::Test
{
protected:
    Bank *bank;
    Admin *admin;
    Admin *nonAdmin;

    void SetUp() override
    {
        bank = new Bank();
        admin = new Admin(100001, "Admin", 35, "admin@bank.com", "9876543210", "adminpass", *bank);

        nonAdmin = new Admin(100002, "NotAdmin", 30, "user@example.com", "1234567890", "userpass", *bank);
    }

    void TearDown() override
    {
        delete bank;
        delete admin;
        delete nonAdmin;
    }
};

TEST_F(BankTest, ConstructorInitializesEmptyBank)
{
    EXPECT_EQ(bank->getAccountHolderCount(), 0);
}

TEST_F(BankTest, CreateAccountSuccessfully)
{
    AccountHolder testHolder(12345, "Test User", 25, "test@example.com", "1234567890", "testpass", 654321, nullptr);

    bool result = bank->createAccount(testHolder, *admin);
    EXPECT_TRUE(result);

    AccountHolder *loggedIn = bank->loginAccountHolder(12345, "testpass");
    EXPECT_NE(loggedIn, nullptr);
    EXPECT_EQ(loggedIn->getName(), "Test User");
}

TEST_F(BankTest, CreateAccountFailsForNonAdmin)
{
    AccountHolder testHolder(54321, "Test User", 25, "test@example.com", "1234567890", "testpass", 654321, nullptr);
    User nonAdminUser(100002, "NotAdmin", 30, "user@example.com", "1234567890", "userpass", UserType::AccountHolder);

    bool result = bank->createAccount(testHolder, nonAdminUser);
    EXPECT_FALSE(result);
}

TEST_F(BankTest, SearchAccountFindsExistingAccount)
{
    AccountHolder testHolder(12345, "Test User", 25, "test@example.com", "1234567890", "testpass", 654321, nullptr);

    bank->createAccount(testHolder, *admin);

    Account *foundAccount = bank->searchAccount(654321, *admin);
    EXPECT_NE(foundAccount, nullptr);
    EXPECT_EQ(foundAccount->getAccountNumber(), 654321);
}

TEST_F(BankTest, SearchAccountReturnsNullForNonExistentAccount)
{
    Account *foundAccount = bank->searchAccount(999999, *admin);
    EXPECT_EQ(foundAccount, nullptr);
}

TEST_F(BankTest, CloseAccountSuccessfully)
{
    AccountHolder testHolder(12345, "Test User", 25, "test@example.com", "1234567890", "testpass", 654321, nullptr);

    bank->createAccount(testHolder, *admin);

    Account *account = bank->searchAccount(654321, *admin);
    EXPECT_NE(account, nullptr);

    bank->closeAccount(654321, *admin);

    Account *closedAccount = bank->searchAccount(654321, *admin);
    EXPECT_EQ(closedAccount, nullptr);
}

TEST_F(BankTest, LoginWithValidCredentials)
{
    AccountHolder testHolder(12345, "Test User", 25, "test@example.com", "1234567890", "testpass", 654321, nullptr);

    bank->createAccount(testHolder, *admin);

    AccountHolder *loggedIn = bank->loginAccountHolder(12345, "testpass");
    EXPECT_NE(loggedIn, nullptr);
    EXPECT_EQ(loggedIn->getName(), "Test User");
    EXPECT_EQ(loggedIn->getUserId(), 12345);
}

TEST_F(BankTest, LoginWithInvalidCredentials)
{
    AccountHolder testHolder(12345, "Test User", 25, "test@example.com", "1234567890", "testpass", 654321, nullptr);

    bank->createAccount(testHolder, *admin);

    AccountHolder *result1 = bank->loginAccountHolder(12345, "wrongpass");
    EXPECT_EQ(result1, nullptr);

    AccountHolder *result2 = bank->loginAccountHolder(54321, "testpass");
    EXPECT_EQ(result2, nullptr);

    AccountHolder *result3 = bank->loginAccountHolder(54321, "wrongpass");
    EXPECT_EQ(result3, nullptr);
}

TEST_F(BankTest, GenerateUniqueUserIds)
{
    int ids[100];
    for (int i = 0; i < 100; i++)
    {
        int userId = bank->generateUniqueUserId();
        EXPECT_GE(userId, 1000);
        EXPECT_LE(userId, 9999);
        for (int j = 0; j < i; j++)
        {
            EXPECT_NE(ids[j], userId);
        }
        ids[i] = userId;
    }
}

TEST_F(BankTest, GenerateUniqueAccountNumbers)
{
    int numbers[100];
    for (int i = 0; i < 100; i++)
    {
        int accountNumber = bank->generateUniqueAccountNumber();
        EXPECT_GE(accountNumber, 100000);
        EXPECT_LE(accountNumber, 999999);
        for (int j = 0; j < i; j++)
        {
            EXPECT_NE(numbers[j], accountNumber);
        }
        numbers[i] = accountNumber;
    }
}

TEST_F(BankTest, MultipleAccountCreationAndResizing)
{
    for (int i = 0; i < 15; i++)
    {
        AccountHolder holder(1000 + i, "User" + std::to_string(i), 25,
                             "user" + std::to_string(i) + "@example.com",
                             "123456789" + std::to_string(i), "pass" + std::to_string(i),
                             600000 + i, nullptr);

        bool result = bank->createAccount(holder, *admin);
        EXPECT_TRUE(result);
    }
    for (int i = 0; i < 15; i++)
    {
        Account *account = bank->searchAccount(600000 + i, *admin);
        EXPECT_NE(account, nullptr);
        EXPECT_EQ(account->getAccountNumber(), 600000 + i);
    }
}