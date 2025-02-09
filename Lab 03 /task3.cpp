#include<iostream>
using namespace std;

class Planner{
    public:
    string arr[12][31];


   void add_task(int month_a,int date_a){
     if((month_a < 1 || month_a > 12)  && ( date_a<1 || date_a > 31)){
                cout<<"invalid month or date " <<endl;
                return;
            }

        else{
            cin.ignore();
        cout<<"enter task to add " << endl;
        getline (cin, arr[month_a -1 ][date_a - 1]);
    }
    
   } 

   void remove_task(int month_r,int date_r){
    if((month_r < 1 || month_r > 12)  &&  (date_r <1 || date_r > 31)){
        cout<<"invalid month or date " <<endl;
        return;
    }
    else{
        arr[month_r - 1][date_r -1] = "";
        cout<<"task has been removed"<<endl;
    }
   
    
 }



   void disply_task(){
    cout<<"details of each month :"<<endl;
    for (int i = 0; i <12; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            if(!arr[i][j].empty()){
                cout<<"Month " << i+1 << " , Date "<< j+1 <<" : " <<  arr[i][j] <<endl;
        }
        
    }
    
   } 

}
};


int main(){
Planner planner;

while (true)
{

cout<<"choose one option\n"<< "1- add\n"<<"2- remove\n"<<"3- disply\n"<<"4-exit"<<endl;
   int month_a,date_a,month_r,date_r;
   int choice;
   cout<<"enter choice : "<<endl;
   cin >> choice;

   switch(choice){
    case 1:
    cout<<"enter month(1-12) to add task"<<endl;
    cin>>month_a;
    cout<<"enter date(1-31) to add task"<<endl;
    cin>>date_a;
    planner.add_task(month_a,date_a);

    break;

    case 2:
    cout<<"enter month(1-12) to add task"<<endl;
    cin>>month_r;
    cout<<"enter date(1-31) to add task"<<endl;
    cin>>date_r;
    planner.remove_task(month_r, date_r);
    break;

    case 3:
    planner.disply_task();
    break;

   

   case 4:
   cout<<"exiting program"<<endl;
   return 0;


   default :
    cout<<"invalid choice try again" <<endl;

   }

}
   return 0;
}
