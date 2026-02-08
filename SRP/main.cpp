#include "Order.h"
#include "PaymentService.h"
#include "DeliveryService.h"
#include "NotificationService.h"

int main() {
    Order order{"Laptop", 1, 500000};

    PaymentService payment;
    DeliveryService delivery;
    NotificationService notification;

    payment.ProcessPayment(order.price * order.quantity);
    delivery.Deliver();
    notification.Send("Order confirmed");

    return 0;
}

