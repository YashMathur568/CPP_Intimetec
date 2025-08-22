#ifndef MOCKTIMESERVICE_H
#define MOCKTIMESERVICE_H

#include "interfaces/ITimeService.h"
#include <gmock/gmock.h>

class MockTimeService : public ITimeService
{
public:
    MOCK_METHOD(std::string, getCurrentTime, (), (override));
};

#endif