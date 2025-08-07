#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

class Transaction
{
public:
    string type;
    double amount;
    string date;

    Transaction(const string t, double amt, const string dt) : type(t), amount(amt), date(dt) {};

    string getType();
    double getAmount();
    string getDate();
};

#endif
