

class Calculator {
private:
    double operand1;
    double operand2;

public:
    // Constructor
    Calculator();

    // Member functions
    double add() const;
    double subtract() const;
    double multiply() const;
    double divide() const;
    
    // Setters
    void setOperands(double op1, double op2);
};


