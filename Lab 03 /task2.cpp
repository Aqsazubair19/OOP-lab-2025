#include<iostream>
using namespace std;

class Teamug{
    public:

    string brand;
    string color;
    int capacity;
    int current_fill_level;


void sip_tea(int sip){
    if(current_fill_level <= 0){
        cout<<"oops! there is no more tea in your mug." <<endl;
    }
    else{
    current_fill_level -= sip;
    capacity = 100 - current_fill_level;
    
    cout<<"current fill level remains =  " << current_fill_level << "%" <<endl;
      cout<<"capacity remains =  " << capacity << "%" <<endl;
    }
}

void refill(){
    if(current_fill_level != 100 ){
        current_fill_level = 100;
        capacity = 0;
        cout<<"your  tea mug is refilled. "<<endl;
    }
    else{

        cout<<"the tea mug is not  refillable. "<<endl;
    }
}


void empty(){
    if(capacity == 100){
        cout<<"your mug is empty, you need a fresh tea mug "<<endl;
    }
    else{
        cout<<"your mug is filled , you need to sip some more tea "<<endl;
    }
}

void checkstatus(){
    cout<< "Brand:  " << brand << endl;
     cout<< "Color: " << color<< endl;
      cout<< "capacity: " << capacity << endl;
      cout<< "current fill level : " << current_fill_level<<endl;

}
};


int main(){
    Teamug mug1;
    mug1.brand = "nescafe";
    mug1.color = "brown";
    mug1.capacity = 0 ;
    mug1.current_fill_level = 100;
     
    cout<<"tea mug status:\n "<<endl; 
    mug1.checkstatus(); 
    
    cout<<endl;
    cout<<"sip some tea :\n"<<endl;
     mug1.sip_tea(70);

    cout<<endl;
    cout<<"tea mug status: \n"<<endl; 
    mug1.checkstatus();

   cout<<endl;
    cout<<"sip some tea :\n"<<endl;
     mug1.sip_tea(30);

    cout<<endl;
   cout<<"tea mug empty check:\n " <<endl;
    mug1.empty();


    cout<<endl;
    cout<<"refill tea check :\n"<<endl;
    mug1.refill();

    cout<<endl;
   cout<<"tea mug empty check:\n " <<endl;
    mug1.empty();

return 0;



    }
