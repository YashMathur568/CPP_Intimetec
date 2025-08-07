#include "Admin.h"
#include <iostream>
using namespace std;

void Admin::createAccountForAccountHolder(AccountHolder &accountHolder)
{
    if (bankRef->createAccount(accountHolder))
    {
        cout << "Account created successfully!" << endl;
    }
    else
    {
        cout << "Account creation failed!" << endl;
    }
}

Account *Admin::searchAccountByNumber(int accountNumber)
{
    return bankRef->searchAccountByNumber(accountNumber);
}

void Admin::closeAccount(int accountNumber)
{
    bankRef->closeAccount(accountNumber);
    cout << "Account closed successfully!" << endl;
}
