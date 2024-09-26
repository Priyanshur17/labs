#include <iostream>
using namespace std;
int main() {
    float weight, height;

  
    cout << "Enter weight in kilograms: ";
    cin >> weight;
    cout << "Enter height in meters: ";
    cin >> height;


    float bmi = weight / (height * height);


    cout << "BMI: " << bmi << endl;
    cout << "BMI Category: ";
    if (bmi < 18.5) {
        cout << "Underweight";
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        cout << "Normal";
    } else if (bmi >= 25 && bmi <= 29.9) {
        cout << "Overweight";
    } else {
        cout << "Obese";
    }

    return 0;
}

