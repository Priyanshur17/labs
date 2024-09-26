// Calculator.cpp
#include "Calculator.h"
#include <iostream>
using namespace std;

// Constructor
Calculator::Calculator() : operand1(0.0), operand2(0.0) {}

double Calculator::add() const {
    return operand1 + operand2;
}

double Calculator::subtract() const {
    return operand1 - operand2;
}

double Calculator::multiply() const {
    return operand1 * operand2;
}

double Calculator::divide() const {
    if (operand2 != 0) {
        return operand1 / operand2;
    } else {
        cerr << "Error: Division by zero!" << endl;
        return 0.0;  // Returning 0 as a default value in case of division by zero
    }
}

void Calculator::setOperands(double op1, double op2) {
    operand1 = op1;
    operand2 = op2;
}
