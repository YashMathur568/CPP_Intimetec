#include <gtest/gtest.h>
#include "User.h"

class UserTest : public ::testing::Test
{
protected:
    User *user;

    void SetUp() override
    {
        user = new User(12345, "Bhavesh Kumar", 30, "Bhavesh@gmail.com", "1234567890", "password123", UserType::AccountHolder);
    }

    void TearDown() override
    {
        delete user;
    }
};

TEST_F(UserTest, ConstructorInitializesAllFields)
{
    EXPECT_EQ(user->getUserId(), 12345);
    EXPECT_EQ(user->getName(), "Bhavesh Kumar");
    EXPECT_EQ(user->getAge(), 30);
    EXPECT_EQ(user->getEmail(), "Bhavesh@gmail.com");
    EXPECT_EQ(user->getContactNumber(), "1234567890");
    EXPECT_EQ(user->getUserType(), UserType::AccountHolder);
}

TEST_F(UserTest, AuthenticateWithValidCredentials)
{
    EXPECT_TRUE(user->authenticate(12345, "password123"));
}

TEST_F(UserTest, AuthenticateWithInvalidUserId)
{
    EXPECT_FALSE(user->authenticate(54321, "password123"));
}

TEST_F(UserTest, AuthenticateWithInvalidPassword)
{
    EXPECT_FALSE(user->authenticate(12345, "wrongpassword"));
}

TEST_F(UserTest, AuthenticateWithBothInvalid)
{
    EXPECT_FALSE(user->authenticate(54321, "wrongpassword"));
}

TEST_F(UserTest, AdminUserType)
{
    User adminUser(99999, "Admin User", 35, "admin@bank.com", "9876543210", "adminpass", UserType::Admin);

    EXPECT_EQ(adminUser.getUserType(), UserType::Admin);
    EXPECT_TRUE(adminUser.authenticate(99999, "adminpass"));
}

TEST_F(UserTest, HandleEmptyName)
{
    User emptyNameUser(11111, "", 25, "empty@test.com", "1111111111", "pass", UserType::AccountHolder);

    EXPECT_EQ(emptyNameUser.getName(), "");
    EXPECT_EQ(emptyNameUser.getUserId(), 11111);
}