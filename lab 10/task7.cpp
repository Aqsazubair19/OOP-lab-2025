#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ofstream out("sensor_log.txt");
    out<< "Sensor 1: 25.5 C";
    streampos pos = out.tellp();
    cout<<"curret pointer position:"<<pos<<endl;


    
    out<<endl<< "Sensor 2: 98.1 %RH";
    streampos pos1 = out.tellp();
    cout<<"current postion after writing second line:"<<pos1<<endl;

    out.close();
    return 0;

}
