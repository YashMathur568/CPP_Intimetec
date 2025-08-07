#include "AccountHolder.h"
#include <iostream>
using namespace std;

void AccountHolder::depositMoney(double amount)
{
    account.deposit(amount);
    cout << "Deposit successful! New Balance: " << account.getBalance() << endl;
}

void AccountHolder::withdrawMoney(double amount)
{
    account.withdraw(amount);
    cout << "Withdrawal successful! New Balance: " << account.getBalance() << endl;
}

void AccountHolder::viewMiniStatement()
{
    account.viewMiniStatement();
}

void AccountHolder::viewFullStatement()
{
    account.viewFullStatement();
}
