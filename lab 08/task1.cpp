#include<iostream>

using namespace std;

class Humidity;

class Temperature{
    private:
    int temperature;

    public:
    Temperature(int temp): temperature (temp){}

     friend int CalculateHeatIndex(Temperature , Humidity );

};

class Humidity{
    int humidity;

    public:
    Humidity(int humi):humidity(humi){}
    
    friend int CalculateHeatIndex(Temperature , Humidity);

};


 int CalculateHeatIndex(Temperature t,  Humidity  h){
    
  float  heatIndex=  t.temperature + 0.33 * h.humidity - 0.70;
     return   heatIndex;

    

}



int main(){
    Temperature t(32);
    Humidity h(70);
    
    float HI = CalculateHeatIndex(t, h);

    cout<<"Heat Idex : "<<HI<<char(248) <<"C"<<endl;


}


