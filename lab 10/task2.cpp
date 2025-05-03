#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;


class ReadFile{

    string  filename;
    ifstream In;
    
  public:
   ReadFile(string filename):filename(filename) , In(filename, ios::in){
     if(!In){
        cerr<<"can't open file"<<endl;
        exit(1);
     }
   }

    void read_data_with_extraction(){
        string st;
        if(In.is_open()){
        while(getline(In,st)){
            cout<<"\nraw line: "<<st<<endl;
        
         istringstream  ss(st);

         string type, id, name, year, extradata, certificate ;


         getline(ss, type, ',');
         getline(ss, id,',');
         getline(ss, name, ',');
         getline(ss ,year,',');
         getline(ss, extradata,',');
         getline(ss, certificate, ',');
         
         
         cout<<"Type: "<<type<<endl;
         cout<<"Id: "<<id<<endl;
         cout<<"Name: "<<name<<endl;
         cout<<"Year: "<<year<<endl;
         cout<<"Extra Data: "<<extradata<<endl;
         cout<<"Certificate: "<<certificate<<endl;


        }

    }
    else{
        cerr<<"can't open file  ...";
        exit(1);
    }
    }

    ~ReadFile(){
     In.close();
     cout<<"\nfile close successfulyy";
    }




};

int main(){
    ReadFile read("vehicle.txt");
    read.read_data_with_extraction();
    return 0;

}
