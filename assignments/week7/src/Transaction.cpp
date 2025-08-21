#include "Transaction.h"

Transaction::Transaction(std::string type, double amount, std::string datetime)
    : type(type), amount(amount), datetime(datetime) {}

std::string Transaction::getType() const
{
    return type;
}

double Transaction::getAmount() const
{
    return amount;
}

std::string Transaction::getDateTime() const
{
    return datetime;
}
