#include<iostream>
using namespace std;


class Teacher;

class Student{
    string name;
    int grade[3] = {70,80,90};

    public:
    Student(string name): name(name){}

    friend class Teacher;
    
    friend void CalculateAverage(Student &);
};

class Teacher{
    

 public:
 Student *s;
    void setStudent(Student *stu){
        s = stu;
    }


    void update_grades(Student *s){
        int new_grade, grade_no;
        cout<<"enter grade no between (0 - 2) to change new grade: "<<endl;
        cin>>grade_no;
        cout<<"enter new grade :"<<endl;
        cin>>new_grade;

        for (int i = 0; i < 3; i++)
        {
            if( i == grade_no){
                s->grade[i] = new_grade;
            

        }
    }
    }


    void view_grades(){
         cout<<"____students details____: "<<endl;
            cout<<"student name:"<<s->name<<endl;

        for (int i = 0; i < 3; i++)
        { 
            cout<<"Grade "<<i+1<<" "<<s->grade[i]<<endl;
        }
        
    }

   friend void CalculateAverage(Student &);

   

};

void CalculateAverage(Student &s){
    int avg = 0;
    for (int i = 0; i < 3; i++)
    {
         avg += s.grade[i];
    }
    

   int  average = avg / 3;
   cout<<"Average: "<<average<<endl;

    
}

int main(){
   Student s("aqsa");
   Teacher t;
   t.setStudent(&s);

   t.view_grades();
   CalculateAverage(s);
   cout<<endl;


   t.update_grades(&s);

   CalculateAverage(s);
}
