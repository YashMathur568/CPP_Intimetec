#include "Transaction.h"

Transaction::Transaction() : type(""), amount(0), datetime("") {}

Transaction::Transaction(std::string type, double amount, std::string datetime)
    : type(type), amount(amount), datetime(datetime) {}

std::string Transaction::getType()
{
    return type;
}

double Transaction::getAmount()
{
    return amount;
}

std::string Transaction::getDateTime()
{
    return datetime;
}