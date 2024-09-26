#include <bits/stdc++.h>
using namespace std;



class Car {
private:
   string make;
   string model;
    int year;

public:

    Car(const string& initialMake, const string& initialModel, int initialYear)
        : make(initialMake), model(initialModel), year(initialYear) {}


    void displayCarDetails() const {
       cout << "Car Details:" <<endl;
       cout << "Make: " << make <<endl;
       cout << "Model: " << model <<endl;
       cout << "Year: " << year <<endl;
    }


    bool isVintageModel() const {
     
        const int currentYear = 2024;  
        return (currentYear - year) >= 25;
    }
};

int main() {
 
    Car myCar("Toyota", "Camry", 1995);

  
    myCar.displayCarDetails();

    if (myCar.isVintageModel()) {
       cout << "This car is a vintage model." <<endl;
    } else {
       cout << "This car is not a vintage model." <<endl;
    }

    return 0;
}
