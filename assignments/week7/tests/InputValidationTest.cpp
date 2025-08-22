#include <gtest/gtest.h>
#include "InputValidation.h"

class InputValidationTest : public ::testing::Test
{
};

TEST_F(InputValidationTest, ValidAge)
{
    EXPECT_TRUE(isValidAge(18));
    EXPECT_TRUE(isValidAge(25));
    EXPECT_TRUE(isValidAge(65));
    EXPECT_TRUE(isValidAge(100));
}

TEST_F(InputValidationTest, InvalidAge)
{
    EXPECT_FALSE(isValidAge(0));
    EXPECT_FALSE(isValidAge(-1));
    EXPECT_FALSE(isValidAge(-100));
}

TEST_F(InputValidationTest, ValidEmail)
{
    std::string validEmail1 = "test@example.com";
    std::string validEmail2 = "user.name@domain.org";
    std::string validEmail3 = "simple@test.co.uk";

    EXPECT_TRUE(isValidEmail(validEmail1));
    EXPECT_TRUE(isValidEmail(validEmail2));
    EXPECT_TRUE(isValidEmail(validEmail3));
}

TEST_F(InputValidationTest, InvalidEmailNoAt)
{
    std::string invalidEmail = "testexample.com";
    EXPECT_FALSE(isValidEmail(invalidEmail));
}

TEST_F(InputValidationTest, InvalidEmailMultipleAt)
{
    std::string invalidEmail = "test@@example.com";
    EXPECT_FALSE(isValidEmail(invalidEmail));
}

TEST_F(InputValidationTest, InvalidEmailNoDotAfterAt)
{
    std::string invalidEmail = "test@example";
    EXPECT_FALSE(isValidEmail(invalidEmail));
}

TEST_F(InputValidationTest, InvalidEmailWithSpaces)
{
    std::string invalidEmail = "test @example.com";
    EXPECT_FALSE(isValidEmail(invalidEmail));
}

TEST_F(InputValidationTest, InvalidEmailEmpty)
{
    std::string invalidEmail = "";
    EXPECT_FALSE(isValidEmail(invalidEmail));
}

TEST_F(InputValidationTest, ValidContact)
{
    std::string validContact1 = "1234567";
    std::string validContact2 = "1234567890";
    std::string validContact3 = "123456789012345";

    EXPECT_TRUE(isValidContact(validContact1));
    EXPECT_TRUE(isValidContact(validContact2));
    EXPECT_TRUE(isValidContact(validContact3));
}

TEST_F(InputValidationTest, InvalidContactTooShort)
{
    std::string invalidContact = "123456";
    EXPECT_FALSE(isValidContact(invalidContact));
}

TEST_F(InputValidationTest, InvalidContactTooLong)
{
    std::string invalidContact = "1234567890123456";
    EXPECT_FALSE(isValidContact(invalidContact));
}

TEST_F(InputValidationTest, InvalidContactWithLetters)
{
    std::string invalidContact = "123abc7890";
    EXPECT_FALSE(isValidContact(invalidContact));
}

TEST_F(InputValidationTest, InvalidContactWithSpecialChars)
{
    std::string invalidContact = "123-456-7890";
    EXPECT_FALSE(isValidContact(invalidContact));
}

TEST_F(InputValidationTest, InvalidContactEmpty)
{
    std::string invalidContact = "";
    EXPECT_FALSE(isValidContact(invalidContact));
}

TEST_F(InputValidationTest, ValidPassword)
{
    std::string validPassword1 = "123456";
    std::string validPassword2 = "password123";
    std::string validPassword3 = "verylongpassword123!@#";

    EXPECT_TRUE(isValidPassword(validPassword1));
    EXPECT_TRUE(isValidPassword(validPassword2));
    EXPECT_TRUE(isValidPassword(validPassword3));
}

TEST_F(InputValidationTest, InvalidPasswordTooShort)
{
    std::string invalidPassword1 = "12345";
    std::string invalidPassword2 = "acsc";
    std::string invalidPassword3 = "";

    EXPECT_FALSE(isValidPassword(invalidPassword1));
    EXPECT_FALSE(isValidPassword(invalidPassword2));
    EXPECT_FALSE(isValidPassword(invalidPassword3));
}