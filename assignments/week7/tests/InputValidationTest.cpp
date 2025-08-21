#include <gtest/gtest.h>
#include "InputValidation.h"

TEST(InputValidationTest, IsValidAge)
{
    EXPECT_TRUE(isValidAge(18));
    EXPECT_TRUE(isValidAge(99));
    EXPECT_FALSE(isValidAge(0));
    EXPECT_FALSE(isValidAge(-1));
    EXPECT_FALSE(isValidAge(250));
}

TEST(InputValidationTest, IsValidEmail)
{
    std::string validEmail1 = "test@example.com";
    std::string validEmail2 = "user.name@example.co.in";
    std::string invalidEmail1 = "test.com";
    std::string invalidEmail2 = "test@com";

    EXPECT_TRUE(isValidEmail(validEmail1));
    EXPECT_TRUE(isValidEmail(validEmail2));
    EXPECT_FALSE(isValidEmail(invalidEmail1));
    EXPECT_FALSE(isValidEmail(invalidEmail2));
}

TEST(InputValidationTest, IsValidContact)
{
    std::string validContact1 = "1234567890";
    std::string validContact2 = "987654321098765";
    std::string invalidContact1 = "12345";
    std::string invalidContact2 = "1234567890123456";
    std::string invalidContact3 = "1234abcd";
    std::string invalidContact4 = "1234567";

    EXPECT_TRUE(isValidContact(validContact1));
    EXPECT_TRUE(isValidContact(validContact2));
    EXPECT_FALSE(isValidContact(invalidContact1));
    EXPECT_FALSE(isValidContact(invalidContact2));
    EXPECT_FALSE(isValidContact(invalidContact3));
    EXPECT_TRUE(isValidContact(invalidContact4));
}

TEST(InputValidationTest, IsValidPassword)
{
    std::string validPassword1 = "password123";
    std::string validPassword2 = "admin2021";
    std::string invalidPassword1 = "123";
    std::string invalidPassword2 = "";

    EXPECT_TRUE(isValidPassword(validPassword1));
    EXPECT_TRUE(isValidPassword(validPassword2));
    EXPECT_FALSE(isValidPassword(invalidPassword1));
    EXPECT_FALSE(isValidPassword(invalidPassword2));
}
