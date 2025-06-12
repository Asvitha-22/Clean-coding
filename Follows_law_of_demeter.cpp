/*  "A method should only talk to its immediate friends and not to strangers."

    That means: a class or method should only interact with:

    Itself

    Its own member variables

    Parameters passed to it

    Objects it creates

    Its direct components (not components of components) 
*/

class Order {
private:
    Customer customer;
public:
    string getShippingCity() {
        return customer.getShippingCity();  // Delegates the call
    }
};

class Customer {
private:
    Address address;
public:
    string getShippingCity() {
        return address.getCity();  // Still delegates
    }
};

class Address {
private:
    string city = "Mumbai";
public:
    string getCity() { return city; }
};

int main() {
    Order order;
    string city = order.getShippingCity();  // ✅ Clean, decoupled
    cout << city << endl;
}

/* Rules

    A member function is allowed to call other member functions in its own class scope directly.
    A member function is allowed to call member functions on member variables that are in its class scope directly.
    If a member function has parameters, the member function is allowed to call the member functions of these parameters directly.
    If a member function creates local objects, the member function is allowed to call member functions on those local objects. Object form of Law of Demeter (DemeterW3; Martin, 2003)
*/
