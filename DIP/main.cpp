#include "EmailNotification.h"
#include "NotificationService.h"

int main() {
    EmailNotification email;
    NotificationService service(&email);
    service.Notify("Order shipped");
    return 0;
}
