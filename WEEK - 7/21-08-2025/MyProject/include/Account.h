#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "NotificationService.h"

class Account
{
    int accountNumber;
    double balance;
    NotificationService *notificationService;

public:
    Account(int accNumber, NotificationService *service);

    void deposit(double amount);

    double getBalance() const;
};

#endif
