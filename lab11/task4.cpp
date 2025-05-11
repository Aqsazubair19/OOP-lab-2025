#include<iostream>
#include<stdexcept>
#include <type_traits>
#include<cmath>


using namespace std;

class NegativeNumberException :public exception{
    public:
    const char* what() const noexcept override{
        return "Input mst be non-negative type!";
    }
};

class InvalidTypeException:public exception{

     public:
    const char* what() const noexcept override{
        return "non-numeric type detected!";
    }
};

template <typename T>
typename enable_if<is_arithmetic<T>::value, T>::type
sqrtcalculation(T num){

    if (num < 0) {
      throw NegativeNumberException();
    } 
    
    cout<<num*num<<endl;
     
    }
   
    

template <typename T> 
typename enable_if<!is_arithmetic<T>::value, T>::type
 sqrtcalculation(T){
        throw InvalidTypeException();
    
}

int main(){
     try {
        cout << "sqrt(9): ";
        sqrtcalculation(9);
        
        sqrtcalculation(-4); 
    } catch (const NegativeNumberException& e) {
        cout << "sqrt(-4): " <<  e.what() << endl;
    }

    try {
        sqrtcalculation("hello");
    } catch (const InvalidTypeException& e) {
        cout << "sqrt(\"hello\"): "  << e.what() << endl;
    }

    

    return 0;

}
