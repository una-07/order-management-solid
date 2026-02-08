#pragma once
#include <iostream>
using namespace std;

class PaymentService {
public:
    void ProcessPayment(double amount) {
        cout << "Payment processed: " << amount << endl;
    }
};

