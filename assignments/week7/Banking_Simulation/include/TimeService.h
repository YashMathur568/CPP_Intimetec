#ifndef TIMESERVICE_H
#define TIMESERVICE_H

#include "interfaces/ITimeService.h"

class TimeService : public ITimeService
{
public:
    std::string getCurrentTime() override;
};

#endif