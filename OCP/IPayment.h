#pragma once

class IPayment {
public:
    virtual void Pay(double amount) = 0;
    virtual ~IPayment() = default;
};

