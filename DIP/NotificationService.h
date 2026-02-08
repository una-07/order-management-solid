#pragma once
#include "INotification.h"

class NotificationService {
    INotification* notification;
public:
    NotificationService(INotification* n) : notification(n) {}
    void Notify(string message) {
        notification->Send(message);
    }
};

