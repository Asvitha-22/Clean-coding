#include <iostream>
class Vehicle
{
    public:

    //closed method(not allowed to ovewrite this method in child class)
    void start()

    {

        std::cout << "key start" << std::endl;

    }

    //override allowed
    virtual void start()

    {

        std::cout << "key start" << std::endl;

    }

    //template method(abstaract method)

    virtual void drive()-0;

    protected:

    Vehicle(){}

};
 
class Bus:public vehicle();

class car:public vehicle()

{

    public:

    void start() override{

        std::cout << "push button start" << std::endl;

    }

}

int main() {

    //write c++ code here

    Bus bobj;

    bobj start();

    car cobj;

    cobj start();

}
 
