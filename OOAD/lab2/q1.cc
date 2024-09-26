#include <bits/stdc++.h>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    

  
    Student(){
    name  = "Unknown";
    rollNumber = 0.0;
    marks = 0.0;
   }
    void inputStudentInfo() {
        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter roll number: ";
        cin >> rollNumber;

        cout << "Enter marks: ";
        cin >> marks;

 
      
    }

    
    void displayStudentInfo() {
        cout << "Student Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    
    Student student1;

    
    cout << "Default Student Information:" << endl;
    student1.displayStudentInfo();

    
    student1.inputStudentInfo();


    student1.displayStudentInfo();

    return 0;
}
