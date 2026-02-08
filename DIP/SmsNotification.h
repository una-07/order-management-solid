#pragma once
#include <iostream>
#include "INotification.h"
using namespace std;

class SmsNotification : public INotification {
public:
    void Send(string message) override {
        cout << "SMS: " << message << endl;
    }
};

