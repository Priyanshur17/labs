#include <iostream>

using namespace std;

class Account {
protected:
    double balance;

public:
    explicit Account(double initialBalance);

    virtual void credit(double amount);
    virtual bool debit(double amount);
    double getBalance() const;
};

Account::Account(double initialBalance) {
    if (initialBalance >= 0.0) {
        balance = initialBalance;
    } else {
        cerr << "Error: Initial balance cannot be negative. Setting balance to 0.0." << endl;
        balance = 0.0;
    }
}

void Account::credit(double amount) {
    balance += amount;
}

bool Account::debit(double amount) {
    if (amount <= balance) {
        balance -= amount;
        return true;
    } else {
        cerr << "Debit amount exceeded account balance." << endl;
        return false;
    }
}

double Account::getBalance() const {
    return balance;
}

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(double initialBalance, double initialInterestRate);

    double calculateInterest();
};

SavingsAccount::SavingsAccount(double initialBalance, double initialInterestRate)
    : Account(initialBalance), interestRate(initialInterestRate) {}

double SavingsAccount::calculateInterest() {
    return balance * interestRate / 100.0;
}

class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    CheckingAccount(double initialBalance, double initialTransactionFee);

    void credit(double amount) override;
    bool debit(double amount) override;
};

CheckingAccount::CheckingAccount(double initialBalance, double initialTransactionFee)
    : Account(initialBalance), transactionFee(initialTransactionFee) {}

void CheckingAccount::credit(double amount) {
    Account::credit(amount);
    balance -= transactionFee; 
}

bool CheckingAccount::debit(double amount) {
    if (Account::debit(amount)) {
        balance -= transactionFee;  
        return true;
    }
    return false;
}

int main() {
    SavingsAccount savingsAccount(1000.0, 5.0);  
    double interestEarned = savingsAccount.calculateInterest();
    savingsAccount.credit(interestEarned);  
    cout << "Savings Account Balance after interest: $" << savingsAccount.getBalance() << endl;

    CheckingAccount checkingAccount(500.0, 2.0);  
    checkingAccount.credit(100.0);  
    checkingAccount.debit(50.0);   
    cout << "Checking Account Balance: $" << checkingAccount.getBalance() << endl;

    return 0;
}