#include "CreditCardPayment.h"

int main() {
    IPayment* payment = new CreditCardPayment();
    payment->Pay(100000);
    delete payment;
    return 0;
}
