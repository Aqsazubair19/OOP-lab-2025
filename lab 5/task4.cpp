#include<iostream>

using namespace std;

class Battery{
    int capacity;


    public:

     Battery(int cap): capacity(cap){}

     int getcapacity(){
        return capacity;
     }

};

class Smartphone{
    Battery battery;

    public:
    Smartphone (Battery b): battery(b){}

    void display(){
    
        cout<<"battery capacity: "<< battery.getcapacity()<<endl;
        cout<<endl;


    }

};

int main(){
Battery b1(100);
Battery b2(50);
Battery b3(80);

Smartphone s1[3] = {b1,b2,b3};

for (int i = 0; i < 3; i++)
{
    cout<<"smartphone " <<i+1<< " details: "<<endl;
    s1[i].display();
}



}
