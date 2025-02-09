#include<iostream>
using namespace std;

class Grocerystore{
    public:
    string items[100];
    int price[100];
    int quantity[100];
    int itemcount = 0;

void add_new_items(string item_name,int item_price , int item_quantity){
  items[itemcount] = item_name;
  price[itemcount] = item_price;
  quantity[itemcount] = item_quantity ;
  itemcount++;
  cout<<item_name<<" has been added succesfully in inventory"<<endl;

  
}

void update_price(string item_name,int new_price){
    bool flag =false;
 for (int i = 0; i < itemcount; i++)
 {
    if(items[i]== item_name){
        price[i] = new_price;
     cout<<items[i] <<" price has been updated"<<endl;
      flag = true;
    }
}
if(!flag ){
    cout<<"item not found"<<endl;

 }
 
}

void view_inventory(){

    for (int i = 0; i < itemcount; i++)
    {
      cout<< items[i] << "- $"<<price[i] << " quntity " <<"("<<quantity[i]<<")" <<endl;

    }
    
}
 
void genrate_receipt(){
    cout<<"receipt of total amount of  each item in inventory:"<<endl;
    int total[100];
    int total_price = 0;
    for (int i = 0; i < itemcount; i++)
    {
      total[i]= price[i] *quantity[i];  
      total_price +=total[i];
    cout<<items[i] <<" :" <<total[i]<<endl;
    }
    cout<<"----------------------------\n TOTAL AMOUNT :" <<total_price<<endl;

}


};

int main(){

    Grocerystore store;
    
    cout<<"\nAdd new items to inventory:"<<endl;
    store.add_new_items("apple",50 ,5);
    store.add_new_items("milk",20,3);
    store.add_new_items("bread",10,5);

    cout<<"\nUpdate items prices of inventory:"<<endl;
    store.update_price("apple",60);
    store.update_price("orange",70);

   cout<<"\nView inventory items:"<<endl;
    store.view_inventory();

    cout<<"\nGenrate receipt for each item:"<<endl;
    store.genrate_receipt();

return 0;


}
