#include<iostream>
using namespace std;

class Books {
public:
    string title;
    double price;
    int *stock;
    static int bookCounter;
    int bookId; 
    
    Books(string t, double p, int s) : title(t), price(p), stock(new int(s)) {
        bookId = ++bookCounter;  
    }


    Books(const Books &b) {
        title = b.title;
        price = b.price;
        stock = new int;  
        *stock = *(b.stock);
        bookId = ++bookCounter;  
        cout << "Book object copied" << endl;
    }


    ~Books() {
        delete stock;  
        cout << "Book object destroyed" << endl;
    }


    void setprice(double p) {
        price = p;
    }

    double getprice() {
        return price;
    }

    int quantity;


    void update_stock() {
        cout << "Enter how many books you want: ";
        cin >> quantity;

        if (*stock >= quantity) {
            cout << "Stock available: " << *stock << endl;
            *stock -= quantity;

            book_purchase();  

            if (*stock == 0) {
                cout << "WARNING! Stock dropped to zero." << endl;
            } else if (*stock < 5) {
                cout << "WARNING! Low stock." << endl;
                cout << "Stock remains: " << *stock << endl;
            } else {
                cout << "Stock remains: " << *stock << endl;
            }
        } else {
            cout << "Stock is not available." << endl;
        }
    }

    
    void book_purchase() {
        double totalprice = quantity * price;  
        apply_discount(totalprice);  

        cout << "Total book purchase price after discount (if any): " << totalprice << endl;
    }


    void apply_discount(double &totalprice) {
        if (quantity > 10) {
            totalprice -= totalprice * 0.10;  // 10% discount
            cout << "Price reduced by 10%" << endl;
        }
        else if (quantity > 5) {
            totalprice -= totalprice * 0.05;  // 5% discount
            cout << "Price reduced by 5%" << endl;
        }
    }

    // Update price with a fixed discount percentage
    void update_price(double baseprice, double discountpercentage) {
        this->price = baseprice;  
        double discount = (this->price * discountpercentage) / 100;  
        this->price -= discount;  

        cout << "Updated price after applying discount: " << this->price << endl;
    }


    void display() {
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << *stock << endl;
    }
};

int Books::bookCounter = 0;

int main() {
    
    Books b1("Oxford", 100.00, 30);
    b1.update_stock();  

    b1.update_price(100.00, 15.00); 
    b1.display();

    Books b2 = b1;
    b2.display();  // Display copied book details

    return 0;
}
