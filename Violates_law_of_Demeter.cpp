/* This is a chain of calls reaching deep into other objects — you're talking to a stranger's stranger.
This violates the Law of Demeter. */

#include<iostream.h>

class Address {
public:
    string city;
    string getCity() { return city; }
};

class Customer {
public:
    Address address;
    Address& getAddress() { return address; }
};

class Order {
public:
    Customer customer;
    Customer& getCustomer() { return customer; }
};

int main() {
    Order order;
    string city = order.getCustomer().getAddress().getCity();  // ❌ Bad
}
