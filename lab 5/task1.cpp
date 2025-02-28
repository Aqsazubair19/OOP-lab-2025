#include<iostream>
using namespace std;

class car{
public:
    int* registration_num;
    string* model;
    string owner_name;

car(int num , string m , string name){
    registration_num = new int(num);
    model = new  string (m);
    owner_name = name;
}
  car(car &c){
    registration_num = c.registration_num;
    model = c.model;
   
  }

void display(){
    cout<<"registration number :" <<*registration_num<<endl;
    cout<<"model name: "<<*model<<endl;
    cout<<"owner name: "<<owner_name<<endl;
}

~car(){
    delete registration_num;
    delete model;
}
};


int main(){
    car c1(122,"bmw","alice");
    car c2 = c1;
    c2.owner_name = "john";
    c1.display();
    cout<<endl;
    
    c2.display();

   
}
