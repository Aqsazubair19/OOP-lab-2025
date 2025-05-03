#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class InventoryItem{
    public:
    int itemId;
    char itemName[20];
};

int main(){
    InventoryItem I1 = {12,"hair care product"};
    ofstream outfile("inventory.dat",ios::binary);
    outfile.write((char*)&I1,sizeof(I1));
    cout<<"item write to file siuccessfully"<<endl;
    outfile.close();

     InventoryItem I2;
    ifstream infile("inventory.dat",ios::binary);
    infile.read((char*)&I2, sizeof(I2));
    infile.close();

    cout<<"Item ID: "<<I2.itemId<<endl;
    cout<<"Item Name:"<<I2.itemName<<endl;

    return 0;


}
