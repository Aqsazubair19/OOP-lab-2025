#include<iostream>
using namespace std;

class Profesors{
    string name;
    string departmentName;


    public:
    Profesors(string n, string dep):name(n), departmentName(dep) {}

  
    string getname(){
        return name;
    }

    string getdepartmentName(){
        return departmentName;
    }



};

class University{

    Profesors *profesor;
   
    
    public:
    University(Profesors *profesor):profesor(profesor){}

void  display(){
        
        cout<<"profesors name: "<<profesor->getname()<<endl;
        cout<<"profesors department name: "<<profesor->getdepartmentName()<<endl;
        cout<<endl;
    

        }
 
    
};




int main(){
    Profesors p1("Ahmed","CS");
    Profesors p2("Ali","AI");
    Profesors P3("Ayan","CY");
    Profesors P4("Sherhyar","SE");

  int count  = 0;
    University u1[4] = {&p1,&p2,&P3,&P4};

    for (int i = count; i < 4; i++)
    {
        cout<<"profesors "<< i+1 <<" details:"<<endl;
        u1[i].display();
    }
    

  return 0;
}
