#include "TimeService.h"
#include <ctime>

std::string TimeService::getCurrentTime()
{
    std::time_t currentTime = std::time(0);
    return std::ctime(&currentTime);
}