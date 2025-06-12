/* Mostly in embedded we should avoid Interface because it is too costly so we need to prefer template approach */

#include <iostream>
using namespace std;
#include <iostream>
class UPIPaymentStratergy{
    
    public :
       void pay(){std::cout<<"Payment Done Using UPI"<<std::endl; }
      
};
class NetbankingPaymentStratergy{
    public :
       void pay(){std::cout<<"Payment Done Using Netbanking"<<std::endl; }
    
};
class CreditCardPayamentStratergy{
    public :
       void pay(){std::cout<<"Payment Done Using Credit Card"<<std::endl; }
    
};

template<typename IPaymentStrategy>   //template approace i.e simplified method overloading
void makePayment(IPaymentStrategy *paymentStratergy){
    paymentStratergy->pay();
}

int main() {
   UPIPaymentStratergy upi;
   makePayment(&upi);
   
   NetbankingPaymentStratergy nb;
   makePayment(&nb);
   
   CreditCardPayamentStratergy ccp;
   makePayment(&ccp);
   
    return 0;
}
