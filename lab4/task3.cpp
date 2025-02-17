#include<iostream>
using namespace std;

#include<iostream>
using namespace std;


class Books{
public:
   string title;
   double price;
   int *stock = new int;


   Books(string t,double p,int s){
    title = t;
    price = p;
    *stock = s;

   }
   Books(const Books &b){
    title = b.title;
    price = b.price;
    stock = new int;
    *stock = *(b.stock);
    cout<<"book object copied"<<endl;

   }

   ~Books(){
    delete stock;
    cout<<"books object destroyed"<<endl;

   }

   void setprice(double p){
     price = p;
   }
   

   double getprice(){
       return price;
   }
int quantity;

void update_stock(){  // it tracks stock level also so no need to make diffrent function
   
  cout<<"enter how many stock you want "<<endl;
  cin>>quantity;
if(*stock >= quantity){
   cout<<"stock available: "<<*stock<<endl;
    *stock -=quantity;
   
   book_purchase();
   if(*stock == 0){
    cout<<"warning! stock drop to zero"<<endl;
   }
else if(*stock < 5 ){
   cout<<"WARNING! low stock "<<endl;
    cout<<"stock remains: "<<*stock<<endl;
}
else{
   cout<<"stock remains: "<<*stock<<endl;
}
}
else{
   cout<<"stock is not available"<<endl;
}
}

void book_purchase(){
     double  totalprice =  quantity*price;

   apply_discount(totalprice);
   cout<<"total book purchases price after discount (if any) is: " <<totalprice<<endl;
}

void apply_discount(double &totalprice){
    if(quantity >10){
        totalprice -= totalprice *0.10;
        cout<<"price reduce by 10% "<<endl;
        }
    else if(quantity > 5){
    totalprice -= totalprice *0.05;
    cout<<"price reduce by 5%"<<endl;
    }
    
}
};

int main(){
 Books b1("oxford",100.00,30);
 b1.update_stock();

Books b2 = b1;
b1.setprice(120.00);
cout<<"update object 1 (orignal book) price : "<<b1.getprice()<<endl;


cout<<"price of copying object (sould remains same): "<<b2.getprice()<<endl;
return 0;


}
