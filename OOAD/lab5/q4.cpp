#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y);

    friend ostream& operator<<(ostream& os, const Date& date);
    friend istream& operator>>(istream& is, Date& date);
};

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

ostream& operator<<(ostream& os, const Date& date) {
    os << date.day << "-" << date.month << "-" << date.year;
    return os;
}

istream& operator>>(istream& is, Date& date) {
    char separator;
    is >> date.day >> separator >> date.month >> separator >> date.year;

    if (is.fail() || separator != '-') {
        throw invalid_argument("Invalid date format. Use DD-MM-YYYY.");
    }

    return is;
}

int main() {
    try {
     
        Date date1(14, 2, 2022);
        cout << "Date 1: " << date1 << endl;

   
        Date date2(0, 0, 0);
        cout << "Enter Date 2 (DD-MM-YYYY): ";
        cin >> date2;
        cout << "Date 2: " << date2 << endl;

        Date date3(21, 12, 2030);
        Date date4(0, 0, 0);
        Date date5(0, 0, 0);

        cout << "Enter Date 4 and Date 5 (DD-MM-YYYY DD-MM-YYYY): ";
        cin >> date4 >> date5;
        cout << "Date 3: " << date3 << ", Date 4: " << date4 << ", Date 5: " << date5 << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}