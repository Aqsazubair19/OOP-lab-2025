#include<iostream>
using namespace std;

class Device{
    protected:
    int DeviceId;
    bool status;

    public:
    Device(int DeviceId,bool status ): DeviceId(DeviceId),status(status){}

    void displayDetails(){
        cout<<"Device ID: "<<DeviceId<<endl;
        cout<<"Status: "<<status<<endl;

    }
};


class SmartPhone: virtual public Device{
    protected:
float screenSize;
public:

SmartPhone(int DeviceId,bool status,float screenSize):
   Device(DeviceId,status),screenSize(screenSize){}
   
   void displayDetails(){
    cout<<"Screen size: "<<screenSize<<endl;
   }


};

class SmartWatch : virtual public Device{
    protected:
bool  heartRateMonitor;
public:
SmartWatch(int DeviceId,bool status,bool heartRateMonitor):
Device(DeviceId,status), heartRateMonitor(heartRateMonitor){}

void displayDetails(){
cout <<"heart Rate Monitor: " <<heartRateMonitor<<endl;
}

};

class SmartWearable : public SmartPhone , SmartWatch{
protected:
 int stepCounter;

 public:
 SmartWearable(int DeviceId,bool status,float screenSize,bool heartRateMonitor,int stepCounter):
 Device(DeviceId,status),
 SmartPhone(DeviceId, status, screenSize),
 SmartWatch(DeviceId,status, heartRateMonitor),
stepCounter(stepCounter){}

void displayDetails(){
    Device ::displayDetails();
    SmartPhone ::displayDetails();
    SmartWatch::displayDetails();
    cout<<"step counter: "<<stepCounter<<endl;
}

};

int main(){
    SmartWearable s1(12,true,14,true,500);
    s1.displayDetails();
    return 0;

}
