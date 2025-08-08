#include "Transaction.h"

Transaction::Transaction() : type(""), amount(0), date("") {}

Transaction::Transaction(std::string t, double amt, std::string dt)
    : type(t), amount(amt), date(dt) {}

std::string Transaction::getType()
{
    return type;
}

double Transaction::getAmount()
{
    return amount;
}

std::string Transaction::getDate()
{
    return date;
}
