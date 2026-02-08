#pragma once
#include <string>
using namespace std;

class INotification {
public:
    virtual void Send(string message) = 0;
    virtual ~INotification() = default;
};

