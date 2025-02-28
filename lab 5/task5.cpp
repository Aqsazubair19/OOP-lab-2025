#include <iostream>
using namespace std;

class TourGuide {
private:
    string name;
    int yearsOfExperience;
    string specialization;

public:
    TourGuide(string n, int years, string spec)
        : name(n), yearsOfExperience(years), specialization(spec) {}

    void display() const {
        cout << "Name: " << name  << ", Years of Experience: " << yearsOfExperience << ", Specialization: " << specialization << endl;
    }
};

class TravelAgency {
private:
    TourGuide *guide;

public:
    TravelAgency(TourGuide *guide) : guide(guide) {}

    void displayAgencyDetails() const {
        cout << "Travel Agency Details:" << endl;
        guide->display();
    }
};

int main() {
    TourGuide guide1("John Doe", 5,"Historical Tours");
    TourGuide guide2("Jane Smith",3,"Adventure Tours");
    TourGuide guide3("Alice Johnson",7,"Cultural Tours");

    TravelAgency agency[3] = { &guide1,&guide2,&guide3 };
    for (int i = 0; i < 3; i++) {
        agency[i].displayAgencyDetails();
    }

    return 0;
}
