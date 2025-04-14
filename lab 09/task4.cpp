#include<iostream>
using namespace std;

class PaymentMethod{

    virtual void processPayment(double amount) = 0;

};

class CreditCard : public PaymentMethod{


string cardNumber;

public:

CreditCard(string cardNumber) : cardNumber(cardNumber){}

void processPayment(double amount){
    if(cardNumber == "1234"){
        cout<<"payment method by credit card is successful"<<endl;
    }
    else{
        cout<<"payment by credit card  is unseccussful"<<endl;
    }

}
};

class DigitalWallet: public PaymentMethod{
  double balance;

  public:
  DigitalWallet(double balance): balance(balance){}

  void processPayment(double amount ){

    
    if(balance >= amount){
        balance -=amount;
         cout<<"payment by digital wallet succesfully "<<endl;
    }
    else{
        cout<<"payment is unseccesfull"<<endl;
    }

  }
};

int main(){
    CreditCard c1("1234");
    c1.processPayment(500.00);

    DigitalWallet d1(5000.00);
    d1.processPayment(5000.00);
    

    CreditCard c2("3333");
    c2.processPayment(500.00);
    
}
