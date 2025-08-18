#include "../src/fib.cpp"
#include <gtest/gtest.h>

TEST(FibTest, NonNegativeValues)
{
    EXPECT_EQ(Fib(0), 0);
    EXPECT_EQ(Fib(1), 1);
    EXPECT_EQ(Fib(5), 5);
    EXPECT_EQ(Fib(6), 8);
}

TEST(FibTest, NegativeValues)
{
    EXPECT_LT(Fib(-1), 0);
    EXPECT_LT(Fib(-10), 0);
}