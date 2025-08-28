#include <gtest/gtest.h>
#include "InputValidation.h"

TEST(InputValidation, ValidAges)
{
    EXPECT_TRUE(isValidAge(18));
    EXPECT_TRUE(isValidAge(25));
    EXPECT_TRUE(isValidAge(65));
    EXPECT_TRUE(isValidAge(100));
}

TEST(InputValidation, ZeroAndNegativeAges)
{
    EXPECT_FALSE(isValidAge(0));
    EXPECT_FALSE(isValidAge(-1));
    EXPECT_FALSE(isValidAge(-100));
}

TEST(InputValidation, CommonEmailFormats)
{
    std::string validEmail1 = "test@example.com";
    std::string validEmail2 = "user.name@yash.org";
    std::string validEmail3 = "simple@test.co.in";

    EXPECT_TRUE(isValidEmail(validEmail1));
    EXPECT_TRUE(isValidEmail(validEmail2));
    EXPECT_TRUE(isValidEmail(validEmail3));
}

TEST(InputValidation, MissingAtSymbol)
{
    std::string invalidEmail = "testexample.com";
    EXPECT_FALSE(isValidEmail(invalidEmail));
}

TEST(InputValidation, MultipleAtSymbols)
{
    std::string invalidEmail = "test@@example.com";
    EXPECT_FALSE(isValidEmail(invalidEmail));
}

TEST(InputValidation, MissingDotAfterAt)
{
    std::string invalidEmail = "test@example";
    EXPECT_FALSE(isValidEmail(invalidEmail));
}

TEST(InputValidation, EmailContainsSpaces)
{
    std::string invalidEmail = "test @example.com";
    EXPECT_FALSE(isValidEmail(invalidEmail));
}

TEST(InputValidation, EmptyEmailString)
{
    std::string invalidEmail = "";
    EXPECT_FALSE(isValidEmail(invalidEmail));
}

TEST(InputValidation, ValidContactLengths)
{
    std::string validContact1 = "1234567";
    std::string validContact2 = "1234567890";
    std::string validContact3 = "123456789012345";

    EXPECT_TRUE(isValidContact(validContact1));
    EXPECT_TRUE(isValidContact(validContact2));
    EXPECT_TRUE(isValidContact(validContact3));
}

TEST(InputValidation, ContactTooShort)
{
    std::string invalidContact = "123456";
    EXPECT_FALSE(isValidContact(invalidContact));
}

TEST(InputValidation, ContactTooLong)
{
    std::string invalidContact = "1234567890123456";
    EXPECT_FALSE(isValidContact(invalidContact));
}

TEST(InputValidation, ContactContainsLetters)
{
    std::string invalidContact = "123abc7890";
    EXPECT_FALSE(isValidContact(invalidContact));
}

TEST(InputValidation, ContactContainsSpecialCharacters)
{
    std::string invalidContact = "123-456-7890";
    EXPECT_FALSE(isValidContact(invalidContact));
}

TEST(InputValidation, EmptyContactString)
{
    std::string invalidContact = "";
    EXPECT_FALSE(isValidContact(invalidContact));
}

TEST(InputValidation, ValidPasswordLengths)
{
    std::string validPassword1 = "123456";
    std::string validPassword2 = "password123";
    std::string validPassword3 = "verylongpassword123!@#";

    EXPECT_TRUE(isValidPassword(validPassword1));
    EXPECT_TRUE(isValidPassword(validPassword2));
    EXPECT_TRUE(isValidPassword(validPassword3));
}

TEST(InputValidation, PasswordTooShortOrEmpty)
{
    std::string invalidPassword1 = "12345";
    std::string invalidPassword2 = "abc";
    std::string invalidPassword3 = "";

    EXPECT_FALSE(isValidPassword(invalidPassword1));
    EXPECT_FALSE(isValidPassword(invalidPassword2));
    EXPECT_FALSE(isValidPassword(invalidPassword3));
}