#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Admin.h"
#include "mocks/MockBank.h"
#include "AccountHolder.h"

class AdminTest : public ::testing::Test
{
protected:
    Admin *admin;
    MockBank *mockBank;
    AccountHolder *testAccountHolder;

    void SetUp() override
    {
        mockBank = new MockBank();
        admin = new Admin(100001, "Admin User", 35, "admin@bank.com", "9876543210", "adminpass", *mockBank);
        testAccountHolder = new AccountHolder(12345, "Test User", 25, "test@gmail.com", "1234567890", "testpass", 654321, nullptr);
    }

    void TearDown() override
    {
        delete testAccountHolder;
        delete admin;
        delete mockBank;
    }
};

TEST_F(AdminTest, ConstructorInitializesAdminUser)
{
    EXPECT_EQ(admin->getUserId(), 100001);
    EXPECT_EQ(admin->getName(), "Admin User");
    EXPECT_EQ(admin->getUserType(), UserType::Admin);
    EXPECT_TRUE(admin->authenticate(100001, "adminpass"));
}

TEST_F(AdminTest, CreateAccountDelegatesToBank)
{
    EXPECT_CALL(*mockBank, createAccount(::testing::Ref(*testAccountHolder), ::testing::Ref(*admin))).WillOnce(::testing::Return(true));

    bool result = admin->createAccountForAccountHolder(*testAccountHolder);
    EXPECT_TRUE(result);
}

TEST_F(AdminTest, SearchAccountDelegatesToBank)
{
    Account *expectedAccount = nullptr;

    EXPECT_CALL(*mockBank, searchAccount(654321, ::testing::Ref(*admin)))
        .WillOnce(::testing::Return(expectedAccount));

    Account *result = admin->searchAccountByNumber(654321);
    EXPECT_EQ(result, expectedAccount);
}

TEST_F(AdminTest, CloseAccountDelegatesToBank)
{
    EXPECT_CALL(*mockBank, closeAccount(654321, ::testing::Ref(*admin))).Times(1);

    admin->closeAccount(654321);
}