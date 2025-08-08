#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction
{
    std::string type;
    double amount;
    std::string date;

public:
    Transaction();
    Transaction(std::string t, double amt, std::string dt);

    std::string getType();
    double getAmount();
    std::string getDate();
};

#endif
