#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    int rollNumber;
    string name;
    string address;
    int age;

public:
    Student(int roll = 0, const string &n = "", const string &addr = "", int a = 0) : rollNumber(roll), name(n), address(addr), age(a) {}

    // Getters
    int getRollNumber() const { return rollNumber; }
    string getName() const { return name; }
    string getAddress() const { return address; }
    int getAge() const { return age; }

    // Setters
    void setRollNumber(int roll) { rollNumber = roll; }
    void setName(const string &n) { name = n; }
    void setAddress(const string &addr) { address = addr; }
    void setAge(int a) { age = a; }

    void display() const
    {
        cout << "Roll Number: " << rollNumber << ", Name: " << name << ", Address: " << address << ", Age: " << age << endl;
    }
};

void addStudent(ofstream &file, const Student &student)
{
    file << student.getRollNumber() << "|" << student.getName() << "|" << student.getAddress() << "|" << student.getAge() << endl;
}

void searchStudent(ifstream &file, int rollNumber)
{
    int roll;
    string name, address;
    int age;
    bool found = false;

    while (file >> roll >> name >> address >> age)
    {
        if (roll == rollNumber)
        {
            found = true;
            cout << "Student found:" << endl;
            cout << "Roll Number: " << roll << ", Name: " << name << ", Address: " << address << ", Age: " << age << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Student with roll number " << rollNumber << " not found." << endl;
    }
}

void updateStudentRecord(const string &filename, int rollNumber)
{
    ifstream inFile(filename);
    ofstream outFile("temp.txt");
    int roll;
    string name, address;
    int age;
    bool found = false;

    if (!inFile || !outFile)
    {
        cerr << "Error: Unable to open file for reading or writing." << endl;
        return;
    }

    while (inFile >> roll >> name >> address >> age)
    {
        if (roll == rollNumber)
        {
            found = true;
            Student student(roll, name, address, age);

            cout << "Enter new details for student with roll number " << rollNumber << ":" << endl;
            cout << "Name: ";
            getline(cin >> ws, name);
            cout << "Address: ";
            getline(cin, address);
            cout << "Age: ";
            cin >> age;

            student.setName(name);
            student.setAddress(address);
            student.setAge(age);

            outFile << student.getRollNumber() << "|" << student.getName() << "|" << student.getAddress() << "|" << student.getAge() << endl;
            cout << "Record updated successfully." << endl;
        }
        else
        {
            outFile << roll << "|" << name << "|" << address << "|" << age << endl;
        }
    }

    if (!found)
    {
        cout << "Student with roll number " << rollNumber << " not found." << endl;
    }

    inFile.close();
    outFile.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

void deleteStudentRecord(const string &filename, int rollNumber)
{
    ifstream inFile(filename);
    ofstream outFile("temp.txt");
    int roll;
    string name, address;
    int age;
    bool found = false;

    if (!inFile || !outFile)
    {
        cerr << "Error: Unable to open file for reading or writing." << endl;
        return;
    }

    while (inFile >> roll >> name >> address >> age)
    {
        if (roll == rollNumber)
        {
            found = true;
            cout << "Record deleted successfully." << endl;
        }
        else
        {
            outFile << roll << "|" << name << "|" << address << "|" << age << endl;
        }
    }

    if (!found)
    {
        cout << "Student with roll number " << rollNumber << " not found." << endl;
    }

    inFile.close();
    outFile.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

void handleException(const std::exception &ex)
{
    cerr << "Error: " << ex.what() << endl;
}

int main()
{
    ofstream file("student_records.txt");
    if (!file.is_open())
    {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    for (int i = 1; i <= 20; ++i)
    {
        Student defaultStudent(i, "Name" + to_string(i), "Address" + to_string(i), 20 + i);
        addStudent(file, defaultStudent);
    }

    file.close();

    char choice;
    int rollNumber;
    string filename = "student_records.txt";

    do
    {
        cout << "\nStudent Record Management System\n";
        cout << "1. Add Student Record\n";
        cout << "2. Search Student Record\n";
        cout << "3. Update Student Record\n";
        cout << "4. Delete Student Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        ofstream outFile;
        ifstream inputFile;

        switch (choice)
        {
        case '1':
        {
            int numOfStudents;
            cout << "Enter the number of students to add: ";
            cin >> numOfStudents;

            outFile.open(filename, ios::app);
            if (!outFile)
            {
                cerr << "Error: Unable to open file for writing." << endl;
                break;
            }

            for (int i = 0; i < numOfStudents; ++i)
            {
                int roll;
                string name, address;
                int age;

                cout << "\nEnter details for student " << i + 1 << ":\n";
                cout << "Roll Number: ";
                cin >> roll;
                cout << "Name: ";
                getline(cin >> ws, name);
                cout << "Address: ";
                getline(cin, address);
                cout << "Age: ";
                cin >> age;

                Student newStudent(roll, name, address, age);
                addStudent(outFile, newStudent);
            }

            outFile.close();
            break;
        }
        case '2':
            cout << "Enter roll number to search: ";
            cin >> rollNumber;
            inputFile.open(filename);
            searchStudent(inputFile, rollNumber);
            inputFile.close();
            break;
        case '3':
            cout << "Enter roll number to update: ";
            cin >> rollNumber;
            updateStudentRecord(filename, rollNumber);
            break;
        case '4':
            cout << "Enter roll number to delete: ";
            cin >> rollNumber;
            deleteStudentRecord(filename, rollNumber);
            break;
        case '5':
            cout << "Exiting program. Thank you.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }

    } while (choice != '5');

    return 0;
}

