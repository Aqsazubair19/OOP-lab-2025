#include<iostream>
using namespace std;

class Vehicle{
    string model;
    double rate;

    public:
    virtual void getDailyRental(double rate) = 0;
    virtual void displayDetails() = 0;

};

class Car : public Vehicle{
   
string currentmodel;
double  currentrate;

public:
    Car(string currentmodel , double currentrate):currentmodel(currentmodel) , currentrate(currentrate) {}

    void getDailyRental(double rate){
        currentrate = rate;
        cout<<"car  rate set to : "<<currentrate<<endl;
    }

    void displayDetails(){
        cout<<"cars details:"<<endl;
        cout<<"model :" <<currentmodel<<endl;
        cout<<"rate: "<<currentrate<<endl;
    }


};

class Bike : public Vehicle{
   
string currentmodel;
double currentrate;

public:
    Bike(string currentmodel , double currentrate):currentmodel(currentmodel) , currentrate(currentrate) {}

    void getDailyRental(double rate){
        currentrate = rate;
        cout<<"bike rate set to  : "<<currentrate<<endl;
    }

    void displayDetails(){
        cout<<"Bike details:"<<endl;
        cout<<"model :" <<currentmodel<<endl;
        cout<<"rate: "<<currentrate<<endl;
    }


};

int main(){
    Car c1("tyota",5000.00);
   

    Bike b1("supra",10000.00);
   
   Vehicle& v1 = c1;  // Vehilce * v1 = &c1;
   Vehicle& v2 = b1;

   v1.getDailyRental(5000.00);
   v1.displayDetails();

   v2.getDailyRental(10000.00);
  v2.displayDetails();


}
