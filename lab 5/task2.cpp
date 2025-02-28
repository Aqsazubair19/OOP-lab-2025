#include<iostream>
using namespace std;

class Patient {
private:
     int patientID;
     int* testResults;
     int numTests;

public:
    Patient(int id, int numTests) {
        patientID = id;
          this->numTests = numTests;
          testResults = new int[numTests];
          for (int i = 0; i < numTests; ++i) {
             testResults[i] = 100 + i;
        }
    }

    Patient(const Patient& p) {
         patientID = p.patientID;
           numTests = p.numTests;
         testResults = new int[numTests];
        for (int i = 0; i < numTests; ++i) {
              testResults[i] = p.testResults[i];
        }
    }

    void display() {
        cout << "Patient ID: " << patientID << endl;
        cout << "Test Results: ";
        for (int i = 0; i < numTests; ++i) {
            cout << testResults[i] << " ";
        }
        cout << endl;
    }

    ~Patient() {
         delete[] testResults;
    }
};

int main() {
    Patient p1(12345, 5);
    cout << "Original Patient (p1) Details: " << endl;
    p1.display();
   
    Patient p2 = p1;

    cout << " Patient (p2) Details: " << endl;
    
    p2.display();

    return 0;
}
