#include <iostream>
#include <concepts>  // Required for C++20 concepts
using namespace std;

//
// 🔷 Abstract Class
//
class Vehicle {
public:
    string brand;

    virtual void show() = 0;  // Pure virtual → abstract
    virtual ~Vehicle() {}     // Virtual destructor
};

//
// ✅ Concrete Class 1
//
class Car : public Vehicle {
public:
    string model;

    Car(string b, string m) {
        brand = b;
        model = m;
    }

    void show() override {
        cout << "This is a car. Brand: " << brand << ", Model: " << model << endl;
    }
};

//
// ✅ Concrete Class 2
//
class Bus : public Vehicle {
public:
    int capacity;

    Bus(string b, int c) {
        brand = b;
        capacity = c;
    }

    void show() override {
        cout << "This is a bus. Brand: " << brand << ", Capacity: " << capacity << " passengers" << endl;
    }
};

//
// 🧩 Concept: Constrain T to only types derived from Vehicle
//
template <typename T>
concept DerivedFromVehicle = std::is_base_of<Vehicle, T>::value;

//
// 🧩 Template Class with Constraint and Inheritance
//
template <DerivedFromVehicle T>
class Garage {
private:
    T item;
public:
    Garage(T i) : item(i) {}

    void display() {
        item.show();  // Calls the appropriate virtual function
    }
};

int main() {
    Car myCar("Honda", "Civic");
    Bus myBus("Mercedes", 55);

    Garage<Car> carGarage(myCar);
    Garage<Bus> busGarage(myBus);

    carGarage.display();
    busGarage.display();

    // ❌ This would fail to compile:
    // Garage<int> invalidGarage(42);  // int is not derived from Vehicle

    return 0;
}
