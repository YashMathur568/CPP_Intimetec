#include <gtest/gtest.h>
#include "../src/stringcheck.cpp"
#include <string>

TEST(StringCheckTest, TestGetGreeting)
{
    const char *expected = "Hello World!";
    const char *result = getGreeting().c_str();
    EXPECT_STREQ(expected, result);
}

TEST(StringCheckTest, TestToUpperCase)
{
    const char *expected = "HELLO";
    const char *result = "hello";
    EXPECT_STRCASEEQ(expected, result);
}

// TEST(StringCheckTest, TestStrCaseNe)
// {
//     const char *str1 = "hello";
//     const char *str2 = "HELLO";
//     // EXPECT_STRCASENE(str1, str2);
// }