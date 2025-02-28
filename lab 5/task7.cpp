#include <iostream>
#include <string>

using namespace std;

class Product {
public:
    int id;
    string name;
    double price;
    Product* next;

    Product(int id, string name, double price) : id(id), name(name), price(price), next(nullptr) {}
};

class Inventory {
private:
    Product* head;

public:
    Inventory() : head(nullptr) {}

    void addProduct(int id, string name, double price) {
        Product* newProduct = new Product(id, name, price);
        if (!head || head->price > price) {
            newProduct->next = head;
            head = newProduct;
            return;
        }

        Product* current = head;
        while (current->next && current->next->price < price) {
            current = current->next;
        }

        newProduct->next = current->next;
        current->next = newProduct;
    }

    void displayProducts() const {
        Product* current = head;
        while (current) {
            cout << "ID: " << current->id << ", Name: " << current->name 
                 << ", Price: $" << current->price << endl;
            current = current->next;
        }
    }

    void searchProduct(string name) const {
        Product* current = head;
        while (current) {
            if (current->name == name) {
                cout << "Product Found - ID: " << current->id 
                     << ", Name: " << current->name 
                     << ", Price: $" << current->price << endl;
                return;
            }
            current = current->next;
        }
        cout << "Product not found!" << endl;
    }

    ~Inventory() {
        while (head) {
            Product* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Inventory storeInventory;

    storeInventory.addProduct(101, "Laptop", 800);
      storeInventory.addProduct(102, "Shirt", 20);
      storeInventory.addProduct(103, "Banana", 1);
     storeInventory.addProduct(104, "Smartphone", 600);

    cout << "Inventory sorted by price:" << endl;
    storeInventory.displayProducts();

    cout << "\nSearching for 'Laptop':" << endl;
    storeInventory.searchProduct("Laptop");

    cout << "\nSearching for 'Tablet':" << endl;
    storeInventory.searchProduct("Tablet");

    return 0;
}
