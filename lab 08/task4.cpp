#include<iostream>

using namespace std;

class Currency{
    int rupee;

    public:
    Currency(int rupee=0 ):rupee(rupee){}

    Currency operator-(){
        return Currency(-rupee);
    }

    Currency operator+(Currency &obj){
        return Currency(rupee + obj.rupee);
    }
    Currency operator-(Currency &obj){
        return Currency(rupee - obj.rupee);
    }
    
    Currency& operator+=(Currency &obj){
        rupee +=obj.rupee;
    }

     
    Currency& operator-=(Currency &obj){
        rupee -=obj.rupee;
    }

 friend   ostream& operator<<(ostream& , Currency &);
};

 ostream& operator<<(ostream& os, Currency &obj){
        os << obj.rupee;
        return os;
    }


    int main(){
        Currency c1(50), c2(10), c3;
        
       // cout<<" addition (+) operation overloadin: "<<endl;
        c3 = c1+c2; // c3 = 60
        cout<<"addition (+) operator overloading: "<<c3<<endl;
        cout<<endl;


       c3 +=c2;
       cout<<"addition assignment  (+=) operator overloading: "<<c3<<endl;
       cout<<endl;

       
       c3 -=c2;  // c3 = 60;
       cout<<"subtraction assignment  (-=) operator overloading: "<<c3<<endl;
       cout<<endl;


        c3 = -c3;  // -60
        cout<< " minus (-) operation overloadin: " <<c3<<endl;
        cout<<endl;

     Currency c4;
       
        c4 = c3 - c2;   // c4 = -70 
        cout<<" subtraction (-) operation overloadin: "<<c4<<endl;
        cout<<endl;
       
       cout<<"<< operator overloading:"<<endl;
        cout<<"c4 :"<<c4;






    }
