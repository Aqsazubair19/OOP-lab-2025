#include<iostream>
#include<fstream>
#include<string>
using namespace std;


class ReadFile{

    ifstream In;
    string  filename;

  public:
   ReadFile(string filename):filename(filename) , In(filename, ios::in){
     if(!In){
        cerr<<"can't open file"<<endl;
        exit(1);
     }
   }

    void read_data(){
        string st;
        if(In.is_open()){
        while(getline(In,st)){
            cout<<st<<endl;
        }

    }
    else{
        cerr<<"can't open file  ...";
        exit(1);
    }
    }
    ~ReadFile(){
     In.close();
     cout<<"file close successfulyy";
    }




};

int main(){
    ReadFile read("vehicle.txt");
    read.read_data();
    return 0;

}
