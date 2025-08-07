#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

enum class UserType
{
    Admin,
    AccountHolder
};

class User
{
protected:
    int userId;
    string name;
    string email;
    string contactNumber;
    UserType userType;

public:
    User() {}
    User(int id, string name, string email, string contactNumber, UserType type)
        : userId(id), name(name), email(email), contactNumber(contactNumber), userType(type) {}

    int getUserId()
    {
        return userId;
    }
    string getName()
    {
        return name;
    }
    string getEmail()
    {
        return email;
    }
    string getContactNumber()
    {
        return contactNumber;
    }

    UserType getUserType()
    {
        return userType;
    }

    virtual ~User() {}
};

#endif
