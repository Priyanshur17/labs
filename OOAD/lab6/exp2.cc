#include <iostream>
#include <sstream>

using namespace std;

class Complex {
private:
    int real;
    int imaginary;

public:
    Complex() : real(0), imaginary(0) {}

    friend ostream& operator<<(ostream& os, const Complex& obj) {
        if (obj.imaginary >= 0) {
            os << obj.real << " + " << obj.imaginary << "i";
        } else {
            os << obj.real << " - " << -obj.imaginary << "i";
        }
        return os;
    }

    friend istream& operator>>(istream& is, Complex& obj) {
        char plusMinus;
        is >> obj.real >> plusMinus >> obj.imaginary;
        
        if (plusMinus == '-') {
            obj.imaginary = -obj.imaginary;
        }
        if (is.fail() || (plusMinus != '+' && plusMinus != '-')) {
            is.setstate(ios::failbit);
        }
        return is;
    }
};

int main() {
    Complex complexNum;

    cout << "Enter a complex number (e.g., 3 + 8i): ";
    if (cin >> complexNum) {
        cout << "You entered: " << complexNum << endl;
    } else {
        cout << "Invalid input!" << endl;
    }

    return 0;
}