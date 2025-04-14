#include<iostream>
using namespace std;

class SmartDevice{

    public:
     virtual void turnOn(bool on) = 0;
     virtual  void turnOff(bool off) =0;
     virtual void getStatus( ) = 0;

};

class LightBulb : public SmartDevice{
    bool isOn;
    int brightness;

    public:
    LightBulb(){}

    LightBulb(int brightness, bool isOn) :
     brightness(brightness) , isOn(isOn){}

     void turnOn(bool isOn){
        isOn == true;

     }

     void turnOff(bool isOn){
        isOn == false;
           
     }

     void getStatus(){
       if(isOn){
         cout<<"light bulb  is on "<<endl;
       }
       else{
        cout<<"light bulb is off"<<endl;
       }
       
     }
};

class Thermostat : public SmartDevice{
     bool isOn;
    double temperature;

    public:
    Thermostat(double temperature, bool isOn) :
     temperature(temperature) , isOn(isOn){}

     void turnOn(bool isOn){
        isOn == true;
     }

     void turnOff(bool isOn){
        isOn == false;
     }

     void getStatus(){
      if(isOn){
         cout<<"temperature control  is active "<<endl;
       }
       else{
        cout<<"temperature control is not active"<<endl;
       }
       
     }
        
     };


int main(){
    LightBulb b1;
    b1.turnOn("true");
    b1.getStatus();

   Thermostat t1(100.00,"true");
   t1.turnOff("false");
   
   t1.getStatus();
   return 0;

}
