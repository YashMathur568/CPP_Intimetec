#include "User.h"

User::User(int userId, std::string name, int age, std::string email, std::string contactNumber, std::string password, UserType userType)
    : userId(userId), name(name), age(age), email(email), contactNumber(contactNumber), password(password), userType(userType) {}

bool User::authenticate(int inputUserId, std::string inputPassword)
{
    return this->userId == inputUserId && this->password == inputPassword;
}

int User::getUserId()
{
    return userId;
}

std::string User::getName()
{
    return name;
}

UserType User::getUserType()
{
    return userType;
}

int User::getAge()
{
    return age;
}

std::string User::getEmail()
{
    return email;
}

std::string User::getContactNumber()
{
    return contactNumber;
}