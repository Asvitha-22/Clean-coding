#include <iostream>
#include <memory>
using namespace std;

// Strategy Interface
class IGreetingStrategy {
public:
    virtual void greet() = 0;
    virtual ~IGreetingStrategy() {}
};

// Concrete Strategy A
class FormalGreeting : public IGreetingStrategy {
public:
    void greet() override {
        cout << "Good morning, sir/madam." << endl;
    }
};

// Concrete Strategy B
class CasualGreeting : public IGreetingStrategy {
public:
    void greet() override {
        cout << "Hey! What's up?" << endl;
    }
};

// Concrete Strategy C
class FriendlyGreeting : public IGreetingStrategy {
public:
    void greet() override {
        cout << "Hello, my friend!" << endl;
    }
};

// Context class
class Greeter {
private:
    unique_ptr<IGreetingStrategy> strategy;
public:
    Greeter(unique_ptr<IGreetingStrategy> s) : strategy(std::move(s)) {}

    void setStrategy(unique_ptr<IGreetingStrategy> s) {
        strategy = std::move(s);
    }

    void greet() {
        strategy->greet();
    }
};

// Test
int main() {
    Greeter greeter(make_unique<FormalGreeting>());
    greeter.greet();  // Outputs: Good morning, sir/madam.

    greeter.setStrategy(make_unique<CasualGreeting>());
    greeter.greet();  // Outputs: Hey! What's up?

    greeter.setStrategy(make_unique<FriendlyGreeting>());
    greeter.greet();  // Outputs: Hello, my friend!
}

/* Greeter greeter(make_unique<FormalGreeting>());  // Dependency injected */
/* 
   | Concept                  | Description                                        | Benefit                         |
   | ------------------------ | -------------------------------------------------- | ------------------------------- |
   | **Strategy Pattern**     | Encapsulate interchangeable behaviors (algorithms) | Reusable, replaceable behaviors |
   | **Dependency Injection** | Provide dependencies from outside the class        | Decoupling and easier testing   |
*/
