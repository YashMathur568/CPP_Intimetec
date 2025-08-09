#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction
{
    std::string type;
    double amount;
    std::string datetime;

public:
    Transaction();
    Transaction(std::string type, double amount, std::string datetime);

    std::string getType();
    double getAmount();
    std::string getDateTime();
};

#endif