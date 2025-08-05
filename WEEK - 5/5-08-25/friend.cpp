#include <iostream>
using namespace std;

class Loan;

class Account
{
private:
    string name;
    int balance;

public:
    Account(string n, int b) : name(n), balance(b) {}
    friend void printUserReport(const Account &, const Loan &);
};

class Loan
{
private:
    int loanAmount;
    float interestRate;

public:
    Loan(int amount, float rate) : loanAmount(amount), interestRate(rate) {}
    friend void printUserReport(const Account &, const Loan &);
};

void printUserReport(const Account &acc, const Loan &loan)
{
    cout << "Account Holder: " << acc.name << endl;
    cout << "Account Balance: ₹" << acc.balance << endl;
    cout << "Loan Amount: ₹" << loan.loanAmount << endl;
    cout << "Interest Rate: " << loan.interestRate << "%" << endl;
}

int main()
{
    Account a("Yash Mathur", 5000);
    Loan l(200, 9.5);

    printUserReport(a, l);
}
