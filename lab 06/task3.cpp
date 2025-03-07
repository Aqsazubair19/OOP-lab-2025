#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}

    void displayDetails()
    {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }
};

class Teacher : public Person
{

protected:
    string subject;

public:
    Teacher(string name, int age, string subject) : Person(name, age), subject(subject) {}

    void displayDetails()
    {
        Person ::displayDetails();
        cout << "subject: " << subject << endl;
    }
};

class Researcher : public Person
{
protected:
    string researchArea;

public:
    Researcher(string name, int age,  string researchArea) : Person(name, age), researchArea(researchArea) {}

    void displayDetails()
    {
        // Person ::displayDetails();
        cout << "Research area :" << researchArea << endl;
    }
};

class Professor : public Researcher  , public Teacher 
{
protected:
    int publications;

public:
    Professor(string name, int age, string subject, string researchArea, int publications) :
     Researcher(name, age, researchArea), Teacher(name,age,subject) , publications(publications) {}

    void displayDetails()

    {
        Teacher  :: displayDetails();
        Researcher :: displayDetails();
        cout << "publication: " << publications << endl;
    }
};

int main()
{
    Professor p1("Ali", 25, "OOP", "Fast_NUCES", 12);
    cout<<"Professors details :"<<endl;
    p1.displayDetails();
    return 0;
}
