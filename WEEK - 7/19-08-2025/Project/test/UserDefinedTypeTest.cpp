#include "../src/UserDefinedType.cpp"
#include <gtest/gtest.h>

TEST(MyTest, CompareObjects)
{
    A objA1, objA2;
    B objB1, objB2;

    EXPECT_EQ(objA1, objA2);

    EXPECT_EQ(objB1, objB2);

    // EXPECT_EQ(objA1, objB1);
    EXPECT_TRUE(compareAB(objA1, objB1));
}