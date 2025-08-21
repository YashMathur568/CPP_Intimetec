#include "Account.h"
#include "NotificationService.h"

Account::Account(int accNumber, NotificationService *service) : accountNumber(accNumber), balance(0), notificationService(service) {}

void Account::deposit(double amount)
{
    balance = balance + amount;
    notificationService->sendNotification("Deposit Successful");
}
double Account::getBalance() const
{
    return balance;
}
