#pragma once
#include <iostream>
#include "IPayment.h"
using namespace std;

class PayPalPayment : public IPayment {
public:
    void Pay(double amount) override {
        cout << "PayPal payment: " << amount << endl;
    }
};

