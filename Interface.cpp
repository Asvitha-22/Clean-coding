// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
//Interface
class IEmployee{
    public:
    virtual void decent() = 0;
    virtual void professional() = 0;
};
//Interface
class IFamilyMember{
    public:
    virtual void casual() = 0;
    virtual void funny() = 0;
    virtual void carring() = 0;
};
// Base class
class Person : public IEmployee,public IFamilyMember{
    public:
    void decent(){}
    void professional(){}
    void casual(){}
void funny(){}
void carring(){}
void reckless(){}
void restless(){}
};
//way accessed through pointer
void officeContext(IEmployee *obj){
    //obj->casual();    -> we can't use this function because object slicing
    obj->decent();
    obj->professional();
}
// way accessed via reference
void familyContext(IFamilyMember &obj){
  obj.casual();
  obj.funny();
  obj.carring();
}

int main() {
    // Object of base class
  Person harry;
  officeContext(&harry);
  familyContext(harry);
  std::cout<<"both success "<<std::endl;
    return 0;
}
