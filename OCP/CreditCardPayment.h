#pragma once
#include <iostream>
#include "IPayment.h"
using namespace std;

class CreditCardPayment : public IPayment {
public:
    void Pay(double amount) override {
        cout << "Credit card payment: " << amount << endl;
    }
};

