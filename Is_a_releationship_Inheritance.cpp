/* One class is a type of another	SportsCar : public Car */

#include <iostream>
using namespace std;

// Base class (general)
class Car {
public:
    void startEngine() {
        cout << "Car engine started." << endl;
    }

    void stopEngine() {
        cout << "Car engine stopped." << endl;
    }
};

// Derived class (specialized)
class SportsCar : public Car {
public:
    void boostSpeed() {
        cout << "Boosting speed!" << endl;
    }
};

int main() {
    SportsCar sc;

    // SportsCar 'is a' Car, so it can use Car's functions
    sc.startEngine();  // Inherited from Car
    sc.boostSpeed();   // Defined in SportsCar
    sc.stopEngine();   // Inherited from Car

    return 0;
}
