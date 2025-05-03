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
         
         
        //  cout<<"Type: "<<type<<endl;
        //  cout<<"Id: "<<id<<endl;
        //  cout<<"Name: "<<name<<endl;
        // cout<<"Year: "<<year<<endl;
          cout<<"Extra Data: "<<extradata<<endl;
        //  cout<<"Certificate: "<<certificate<<endl;


        if(type == "AutonomousCar"){
          size_t colonPostion =  extradata.find(':');
            if(colonPostion != string::npos){
                try{
                    string st = extradata.substr(colonPostion+1);
                    float st1 = stof(st);
                    cout<<"ID: "<<id<<", Software version: "<<st1<<endl;
                }
                catch(...){
                    cout<<"invalid software version format"<<endl;
                }
            }
        }
        else if(type == "ElectricVehicle"){
            size_t colonPostion =  extradata.find(':');
            if(colonPostion != string::npos){
                try{
                    string st = extradata.substr(colonPostion+1);
                    float st1 = stoi(st);
                    cout<<"ID: "<<id<<", Battery: "<<st1<<endl;
                }
                catch(...){
                    cout<<"invalid battery capacity  format"<<endl;
                }
            }
        }
 
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
