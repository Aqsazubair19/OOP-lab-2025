#include<iostream>
using namespace std;

class Librarian;
class Book{
string title;
int price;


public:
Book(string title, int price): title(title), price(price){}
friend class Librarian;

};

class Librarian{
     public: 
   Book *b;
 float Discount;

 void  setBook(Book *book){
    b = book;
 }


 float  discount(Book *b){
   Discount = b->price * 0.10;
    return Discount;

   }

   void display(){
    cout<<"___________BOOKS DETAILS:__________ "<<endl;
    cout<<"Title : "<<b->title<<endl;
    cout<<"Price before discount  : "<<b->price<<endl;
    cout<<"price after discount: "<< b->price - Discount<<endl;
   }

   

};

int main(){
    Book b("oxford",500);
    Librarian L;
    
    L.setBook(&b);
    L.discount(&b);
    L.display();


}
