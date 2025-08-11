#ifndef USER_H
#define USER_H

#include <string>

enum class UserType
{
    Admin,
    AccountHolder
};

class User
{
protected:
    int userId;
    std::string name;
    int age;
    std::string email;
    std::string contactNumber;
    std::string password;
    UserType userType;

public:
    User();
    User(int userId, std::string name, int age, std::string email, std::string contactNumber, std::string password, UserType userType);

    bool authenticate(int inputUserId, std::string inputPassword);

    int getUserId();
    std::string getName();
    UserType getUserType();
    std::string getPassword();
    int getAge();
    std::string getEmail();
    std::string getContactNumber();
};

#endif