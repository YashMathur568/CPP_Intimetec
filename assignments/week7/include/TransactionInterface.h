#ifndef TRANSACTION_INTERFACE_H
#define TRANSACTION_INTERFACE_H

#include <string>

class TransactionInterface
{
public:
    virtual ~TransactionInterface() = default;
    virtual std::string getType() const = 0;
    virtual double getAmount() const = 0;
    virtual std::string getDateTime() const = 0;
};

#endif
