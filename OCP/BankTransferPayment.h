#pragma once
#include <iostream>
#include "IPayment.h"
using namespace std;

class BankTransferPayment : public IPayment {
public:
    void Pay(double amount) override {
        cout << "Bank transfer payment: " << amount << endl;
    }
};

