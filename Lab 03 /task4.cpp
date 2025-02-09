#include<iostream>
using namespace std;

class Laptop{
    public:
    string brand;
    string model;
    string processor;
    int storage;
    int ram;
   bool ison;

Laptop(string b,string m,string p,int s,int r){
 brand = b;
 model = m;
 processor= p;
 storage = s;
 ram = r;
 ison = false;
}


   void turn_on(){
       if(!ison){
        ison = true;
        cout<< brand<< " " << model<< " is now turn on " <<endl;
       }
       else{
        cout<< brand<< " " << model<< " is already on " <<endl;
       }
    }



    void turn_off(){
        if(ison){
            ison = false;
         cout<< brand<< " " << model<< " is now turn off " <<endl;
        }
        else{
         cout<< brand<< " " << model<< " is already off " <<endl;
        }
     }
 

     void run_program(string program_name){
        if(ison){
            cout<<"program " <<program_name<< " running on " << brand << " " << model<<endl;
        }
        else{
            cout<<"program " <<program_name<< " can't run , please turn on the laptop first."  <<endl;
        }
     }

    void check_specificatons(){
       cout <<"Laptop specifications"<<endl;
       cout<<"Brand : " <<brand<<endl;
       cout<<"Model: "<<model<<endl;
       cout<<"Processor: " <<processor<<endl;
       cout<<"Storage: " << storage<<" GB"<<endl;
       cout<<"Ram: "<<ram<<" GB"<<endl;

    }

    static void  compare_specifications(Laptop l1, Laptop l2){
        //compare ram:
        if(l1.ram > l2.ram){
            cout<<l1.brand << " "<<l1.model << " has more RAM"<<endl;
        }
        else if(l2.ram >l1.ram){
            cout<<l2.brand << " "<<l2.model << " has more RAM"<<endl;
        }
        else{
            cout<<"both laptop have same RAM"<<endl;
        }


     //compare storage:
     if(l1.storage > l2.storage){
        cout<<l1.brand << " "<<l1.model << " has more storage"<<endl;
    }
    else if(l2.storage >l1.storage){
        cout<<l2.brand << " "<<l2.model << " has more storage"<<endl;
    }
    else{
        cout<<"both laptop have same storage"<<endl;
    }

    // compare processor:
    if(l1.processor > l2.processor){
        cout<<l1.brand << " "<<l1.model << " has better processor"<<endl;
    }
    else if(l2.processor >l1.processor){
        cout<<l2.brand << " "<<l2.model << " has better processor"<<endl;
    }
    else{
        cout<<"both laptop have same processor"<<endl;
    }

        }

        };


int main(){
    Laptop bilallaptop("Dell","intel i5","XPS 15",16,512);
    Laptop ayeshalaptop("Dell","intel i7","XPS 17",20,515);
    cout<<"bilal's ";
    bilallaptop.check_specificatons();
    cout<<"ayesha's ";
    ayeshalaptop.check_specificatons();

cout<<"\nbilals's laptop turn on / off: "<<endl;
    bilallaptop.turn_on();
    bilallaptop.turn_off();

    cout<<"\nayesha's laptop turn on / off: "<<endl;
    ayeshalaptop.turn_off();
    ayeshalaptop.turn_on();

    cout<<"\nbilals's laptop program run:"<<endl;
    bilallaptop.run_program("microsoft world");

    cout<<"\nayesha's laptop program run: "<<endl;
    ayeshalaptop.run_program("microsoft world");

    
  cout<<"\ncompare bilal's and ayesha's laptop"<<endl;

    Laptop::compare_specifications(bilallaptop,ayeshalaptop);

    return 0;

}
