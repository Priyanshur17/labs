#include <bits/stdc++.h>
using namespace std;

class Loan {
private:
    string customerName;
    double loanAmount;
    double interestRate;

public:
    Loan(const string& name, double amount, double rate)
        : customerName(name), loanAmount(amount), interestRate(rate) {}

    double calculateMonthlyPayment(int loanTermMonths)  {
        double monthlyInterestRate = interestRate / 100 ;

        double monthlyPayment = (loanAmount *monthlyInterestRate ) + loanAmount/loanTermMonths;

        return monthlyPayment;
    }

    void displayLoanInfo(int loanTermMonths)  {
        cout << "Loan Information:" << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Loan Amount: $" << loanAmount << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Loan Term: " << loanTermMonths << " months" << endl;

        double monthlyPayment = calculateMonthlyPayment(loanTermMonths);
        cout << "Monthly Payment: $" << monthlyPayment << endl;
    }
};

int main() {
    Loan myLoan("John Doe", 5000.0, 5.0);

    myLoan.displayLoanInfo(12);

    return 0;
}
