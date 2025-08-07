#include <iostream>
#include "Bank.h"
#include "AccountHolder.h"
#include "Admin.h"

using namespace std;

void showAdminMenu()
{
    cout << "\n    Admin Menu    " << endl;
    cout << "1. Create Account for Account Holder" << endl;
    cout << "2. Search Account by Number" << endl;
    cout << "3. Close Account" << endl;
    cout << "4. Exit" << endl;
}

void showAccountHolderMenu()
{
    cout << "\n   Account Holder Menu   " << endl;
    cout << "1. Deposit Money" << endl;
    cout << "2. Withdraw Money" << endl;
    cout << "3. View Mini Statement" << endl;
    cout << "4. View Full Statement" << endl;
    cout << "5. Exit" << endl;
}

int main()
{
    Bank bank;
}
