#include<iostream>
using namespace std;

class MarkerPen{
    public:
    string brand;
    string color;
    int inklevel;
    bool reffilibile;


   void write(int usage ){
       if(inklevel <= 0){
          cout<<"the pen is out of ink"<<endl;

       }
       else{
          inklevel -= usage;
          cout<< "  inklevel remain  =  "<< inklevel << "%" <<endl;

       }
   }


void refill(){
    if(reffilibile){
        inklevel = 100;
        cout<<"the pen is refilled"<<endl;
    }
    else{
        cout<<"the marker pen is not reffilible"<<endl;
    }
    
}

void checkstatus(){
    cout<< "Brand:  " << brand << endl;
     cout<< "Color: " << color<< endl;
      cout<< "inklevel: " << inklevel << endl;

if(inklevel == 100){
    cout<<"reffibility : " << "no " <<endl;
}
else{
       cout<< "reffilibility: " << (reffilibile ? "yes" : "no" ) << endl;
}
    }
};

int main(){
    MarkerPen mypen;
    mypen.brand = "Dollar";
    mypen.color = "Black";
    mypen.inklevel = 100;
    mypen.reffilibile = true;
    
   mypen.checkstatus();
   mypen.write(70);
   
   mypen.checkstatus();

   mypen.refill();      

   mypen.checkstatus();
   return 0;




} 
