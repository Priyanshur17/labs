#include <bits/stdc++.h>
using namespace std;

class BankAccount {
protected:
   string customerName;
    double balance;

public:
    BankAccount(const string& name, double initialBalance)
        : customerName(name), balance(initialBalance) {}

    virtual void deposit(double amount) = 0;   
    virtual void withdrawal(double amount) = 0; 

    void display() const {
       cout << "Customer: " << customerName <<endl;
       cout << "Balance: $" << balance <<endl;
    }
};

class SavingAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingAccount(const string& name, double initialBalance, double interest)
        : BankAccount(name, initialBalance), interestRate(interest) {}


    void deposit(double amount) override {
        balance += amount;
        balance += (balance * interestRate / 100); 
    }

    void withdrawal(double amount) override {
        if (balance >= amount) {
            balance -= amount;
        } else {
           cout << "Insufficient funds for withdrawal." <<endl;
        }
    }
};

class Overdraft : public BankAccount {
private:
    double overdraftLimit;

public:
    Overdraft(const string& name, double initialBalance, double limit)
        : BankAccount(name, initialBalance), overdraftLimit(limit) {}

   
    void deposit(double amount) override {
        balance += amount;
    }

    void withdrawal(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
        } else {
           cout << "Withdrawal exceeds overdraft limit." <<endl;
        }
    }
};

int main() {
    SavingAccount savingAccount("Alice", 1000.0, 5.0);
    Overdraft overdraftAccount("Bob", 500.0, 200.0);

    savingAccount.deposit(200.0);
    savingAccount.withdrawal(150.0);
    savingAccount.display();

    overdraftAccount.deposit(100.0);
    overdraftAccount.withdrawal(700.0);
    overdraftAccount.display();

    return 0;
}
