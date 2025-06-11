#include <iostream>
using namespace std;

// 🔹 Generalization: A general base class for all animals
class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }

    void sleep() {
        cout << "This animal sleeps." << endl;
    }

    // Virtual function to allow specialization
    virtual void makeSound() {
        cout << "Animal makes a sound." << endl;
    }
};

// 🔸 Specialization: Dog is a specific type of Animal
class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Dog barks." << endl;
    }

    void fetch() {
        cout << "Dog fetches the ball." << endl;
    }
};

// 🔸 Specialization: Cat is another specific type of Animal
class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Cat meows." << endl;
    }

    void climb() {
        cout << "Cat climbs the tree." << endl;
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->eat();
    a1->makeSound(); // Dog barks.

    a2->sleep();
    a2->makeSound(); // Cat meows.

    delete a1;
    delete a2;

    return 0;
}
