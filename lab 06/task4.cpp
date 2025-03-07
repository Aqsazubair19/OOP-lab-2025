#include<iostream>
using namespace std;

class Account{
protected:

int accountNumber; 
float balance;
public:

Account(int accountNumber, float balance):accountNumber(accountNumber),balance(balance){}

void  displayDetails(){
  cout<<" Account number: "<<accountNumber<<endl;
  cout<<"Balnce: "<<balance<<endl;


}


};

class SavingsAccounts : public Account{
 protected:
   float interestRate;

   public:

SavingsAccounts(int accountNumber, float balance,float interestRate):
 Account(accountNumber,balance), interestRate(interestRate){}


 void displayDetails(){
    Account ::displayDetails();
    cout<<" Intrest rate: "<<interestRate<<endl;
   }



};

class CheckingAccount: public Account{
   protected:
  float overdraftLimit;

  public:
  CheckingAccount(int accountNumber, float balance,float overdraftLimit):
  Account(accountNumber,balance),overdraftLimit(overdraftLimit){}

  void displayDetails(){
    Account ::displayDetails();
    cout<<"Overdraft Limit: "<<overdraftLimit<<endl;
  }
};

int main(){
    cout<<"saving account details:"<<endl;
SavingsAccounts s1(101,5000,500);
s1.displayDetails();
cout<<endl;
cout<<"checking account deatils: "<<endl;
CheckingAccount c1(102,10000,500);
c1.displayDetails();


return 0;


}
