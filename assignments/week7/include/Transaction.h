#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "TransactionInterface.h"
#include <string>

class Transaction : public TransactionInterface
{
private:
    std::string type;
    double amount;
    std::string datetime;

public:
    Transaction(std::string type, double amount, std::string datetime);

    std::string getType() const override;
    double getAmount() const override;
    std::string getDateTime() const override;
};

#endif
