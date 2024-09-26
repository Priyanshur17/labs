// main.cpp
#include <iostream>
#include "Calculator.h"
using namespace std;


int main() {
    Calculator calculator;

    calculator.setOperands(10.0, 5.0);

    cout << "Addition: " << calculator.add() << endl;
    cout << "Subtraction: " << calculator.subtract() << endl;
    cout << "Multiplication: " << calculator.multiply() << endl;
    cout << "Division: " << calculator.divide() << endl;

    calculator.setOperands(8.0, 0.0);
    cout << "Division: " << calculator.divide() << endl;

    return 0;
}
