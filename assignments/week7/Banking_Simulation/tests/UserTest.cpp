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
