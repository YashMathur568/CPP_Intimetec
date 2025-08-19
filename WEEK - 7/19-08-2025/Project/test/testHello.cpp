#include "../src/sayHello.cpp"
#include <gtest/gtest.h>

TEST(HelloTest, canGetHelloWithEmpty)
{
    EXPECT_EQ(sayHello(""), "Hello World");
}

TEST(HelloTest, canGetHelloWithName)
{
    EXPECT_EQ(sayHello("Yash"), "Hello Yash");
}