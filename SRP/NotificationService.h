#pragma once
#include <iostream>
#include <string>
using namespace std;

class NotificationService {
public:
    void Send(string message) {
        cout << message << endl;
    }
};

