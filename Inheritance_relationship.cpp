/* A Subclass inherits from a Superclass

Used when one class "is a type of" another */

/* Teacher is a Person. It inherits behavior and state from Person. */

class Person {
protected:
    std::string name;
public:
    Person(const std::string& name) : name(name) {}
};

class Teacher : public Person {
public:
    Teacher(const std::string& name) : Person(name) {}
    void teach() { std::cout << name << " is teaching.\n"; }
};
