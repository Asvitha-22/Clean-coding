#include <iostream>
#include <memory>
using namespace std;

// Interface (abstraction for dependency)
class INotificationService {
public:
    virtual void send(string message) = 0;
    virtual ~INotificationService() {}
};

// Concrete dependency 1
class EmailService : public INotificationService {
public:
    void send(string message) override {
        cout << "[Email] " << message << endl;
    }
};

// Concrete dependency 2
class SMSService : public INotificationService {
public:
    void send(string message) override {
        cout << "[SMS] " << message << endl;
    }
};

// Concrete dependency 3
class PushNotificationService : public INotificationService {
public:
    void send(string message) override {
        cout << "[Push Notification] " << message << endl;
    }
};

// Dependent class (depends on abstraction)
class NotificationManager {
private:
    unique_ptr<INotificationService> service;
public:
    // Constructor Injection
    NotificationManager(unique_ptr<INotificationService> svc) 
        : service(std::move(svc)) {}

    void notifyUser(const string& msg) {
        service->send(msg);
    }

    // Setter Injection (optional flexibility)
    void setService(unique_ptr<INotificationService> svc) {
        service = std::move(svc);
    }
};

// --- Main test ---
int main() {
    // Inject EmailService
    NotificationManager manager(make_unique<EmailService>());
    manager.notifyUser("Welcome to our app!");

    // Switch to SMSService
    manager.setService(make_unique<SMSService>());
    manager.notifyUser("Your OTP is 123456");

    // Switch to Push Notification
    manager.setService(make_unique<PushNotificationService>());
    manager.notifyUser("You have a new message!");

    return 0;
}
