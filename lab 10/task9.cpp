#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main(){
     
    ifstream in("large_log.txt");
    string content;
    getline(in,content);
    streampos pos = in.tellg();
    cout<<"line read from file: "<<content<<endl;
    cout<<"current position of pointer:"<<pos<<endl;
    
    string line;
    getline(in,line);
    streampos pos1 = in.tellg();
    cout<<"line read from file: "<<line<<endl;
    cout<<"current position of pointer:"<<pos1<<endl;

    in.close();
    return 0;
  

}
