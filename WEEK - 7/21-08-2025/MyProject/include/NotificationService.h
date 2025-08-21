#ifndef NOTIFICATIONSERVICE_H
#define NOTIFICATIONSERVICE_H

#include <string>

class NotificationService
{
public:
    virtual void sendNotification(const std::string &message) = 0;
    virtual ~NotificationService();
};

#endif
