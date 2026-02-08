#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class IPayment {
public:
    virtual void ProcessPayment(double amount) = 0;
    virtual ~IPayment() = default;
};

class CreditCardPayment : public IPayment {
public:
    void ProcessPayment(double amount) override {
        cout << "Paid by credit card: " << amount << endl;
    }
};

class PayPalPayment : public IPayment {
public:
    void ProcessPayment(double amount) override {
        cout << "Paid via PayPal: " << amount << endl;
    }
};

class BankTransferPayment : public IPayment {
public:
    void ProcessPayment(double amount) override {
        cout << "Paid by bank transfer: " << amount << endl;
    }
};

class IDelivery {
public:
    virtual void DeliverOrder() = 0;
    virtual ~IDelivery() = default;
};

class CourierDelivery : public IDelivery {
public:
    void DeliverOrder() override {
        cout << "Delivered by courier" << endl;
    }
};

class PostDelivery : public IDelivery {
public:
    void DeliverOrder() override {
        cout << "Delivered by post service" << endl;
    }
};

class PickUpPointDelivery : public IDelivery {
public:
    void DeliverOrder() override {
        cout << "Delivered to pickup point" << endl;
    }
};

class INotification {
public:
    virtual void SendNotification(const string& message) = 0;
    virtual ~INotification() = default;
};

class EmailNotification : public INotification {
public:
    void SendNotification(const string& message) override {
        cout << "Email notification: " << message << endl;
    }
};

class SmsNotification : public INotification {
public:
    void SendNotification(const string& message) override {
        cout << "SMS notification: " << message << endl;
    }
};

class IDiscountRule {
public:
    virtual double Apply(double total) = 0;
    virtual ~IDiscountRule() = default;
};

class PercentageDiscount : public IDiscountRule {
    double percent;
public:
    PercentageDiscount(double p) : percent(p) {}
    double Apply(double total) override {
        return total * (1 - percent);
    }
};

class DiscountCalculator {
    vector<shared_ptr<IDiscountRule>> rules;
public:
    void AddRule(shared_ptr<IDiscountRule> rule) {
        rules.push_back(rule);
    }
    double Calculate(double total) {
        for (auto& rule : rules)
            total = rule->Apply(total);
        return total;
    }
};

struct OrderItem {
    string name;
    int quantity;
    double price;
};

class Order {
    vector<OrderItem> items;
    shared_ptr<IPayment> payment;
    shared_ptr<IDelivery> delivery;
public:
    void AddItem(const string& name, int quantity, double price) {
        items.push_back({name, quantity, price});
    }
    void SetPayment(shared_ptr<IPayment> p) {
        payment = p;
    }
    void SetDelivery(shared_ptr<IDelivery> d) {
        delivery = d;
    }
    double CalculateTotal() const {
        double total = 0;
        for (const auto& item : items)
            total += item.price * item.quantity;
        return total;
    }
    void Pay(double amount) {
        payment->ProcessPayment(amount);
    }
    void Deliver() {
        delivery->DeliverOrder();
    }
};

int main() {
    Order order;
    order.AddItem("Laptop", 1, 500000);
    order.AddItem("Mouse", 2, 5000);

    DiscountCalculator discountCalculator;
    discountCalculator.AddRule(make_shared<PercentageDiscount>(0.1));

    double total = order.CalculateTotal();
    double finalPrice = discountCalculator.Calculate(total);

    order.SetPayment(make_shared<CreditCardPayment>());
    order.SetDelivery(make_shared<CourierDelivery>());

    order.Pay(finalPrice);
    order.Deliver();

    shared_ptr<INotification> notification = make_shared<EmailNotification>();
    notification->SendNotification("Order successfully processed");

    return 0;
}

