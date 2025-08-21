#ifndef MOCKNOTIFICATIONSERVICE_H
#define MOCKNOTIFICATIONSERVICE_H

#include <gmock/gmock.h>
#include "NotificationService.h"

// Mock class to simulate NotificationService
class MockNotificationService : public NotificationService
{
public:
    MOCK_METHOD(void, sendNotification, (const std::string &message), (override));
};

#endif
