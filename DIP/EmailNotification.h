#pragma once
#include <iostream>
#include "INotification.h"
using namespace std;

class EmailNotification : public INotification {
public:
    void Send(string message) override {
        cout << "Email: " << message << endl;
    }
};

