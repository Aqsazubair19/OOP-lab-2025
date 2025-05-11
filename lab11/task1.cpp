#include<iostream>
#include<sstream>
#include <stdexcept>
using namespace std;


class InvalidValueException : public exception{
    public:

    const char* what() const noexcept override{
        return "InvalidValueException - Age cannot be negative or exceed 120";

    }


    
};

void validateAge(int age){
    try{
        if(age>=0 && age <=120){
            cout<<"valid age: "<<age<<endl;
        }
        else{
            throw InvalidValueException();
        }
    }
    catch(InvalidValueException &e){
        cout<<e.what()<<endl;

    }
}


int main(){
   
    int age;
    cout<<"enter age:"<<endl;
    cin>>age;

    validateAge(age);
    return 0;

}
