#ifndef ITIMESERVICE_H
#define ITIMESERVICE_H

#include <string>

class ITimeService
{
public:
    virtual std::string getCurrentTime() = 0;
    virtual ~ITimeService() = default;
};

#endif