#include <gtest/gtest.h>
#include "User.h"

TEST(UserTest, ConstructorAndAuthenticate)
{

    int userId = 12345;
    std::string name = "John Doe";
    int age = 30;
    std::string email = "johndoe@example.com";
    std::string contactNumber = "1234567890";
    std::string password = "password123";

    User user(userId, name, age, email, contactNumber, password, UserType::AccountHolder);

    EXPECT_EQ(user.getUserId(), userId);
    EXPECT_EQ(user.getName(), name);
    EXPECT_EQ(user.getAge(), age);
    EXPECT_EQ(user.getEmail(), email);
    EXPECT_EQ(user.getContactNumber(), contactNumber);

    EXPECT_TRUE(user.authenticate(userId, password));
    EXPECT_FALSE(user.authenticate(userId, "wrongpassword"));
}
