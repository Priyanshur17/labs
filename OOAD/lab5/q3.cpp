#include <iostream>
#include <vector>

using namespace std;

class Customer;

class Account {
private:
    int accountNumber;
    double balance;
    Customer* customer;

public:
    Account(int accNumber, double initialBalance, Customer* cust);

    void deposit(double amount);
    bool withdraw(double amount);
    void displayDetails() const;

    friend class Transaction;
};

class Customer {
private:
    string name;
    string address;
    string contactInfo;

public:
    Customer(string n, string addr, string contact);

    string getName() const;
    string getAddress() const;
    string getContactInfo() const;

    friend class Account;
};

class Transaction {
private:
    int transactionID;
    double amount;
    Account* sourceAccount;
    Account* destinationAccount;

public:
    Transaction(int transID, double amt, Account* srcAccount, Account* destAccount);

    void executeTransaction();

    friend void transferFunds(Account& source, Account& destination, double amount);
};

Customer::Customer(string n, string addr, string contact)
    : name(n), address(addr), contactInfo(contact) {}

string Customer::getName() const {
    return name;
}

string Customer::getAddress() const {
    return address;
}

string Customer::getContactInfo() const {
    return contactInfo;
}

Account::Account(int accNumber, double initialBalance, Customer* cust)
    : accountNumber(accNumber), balance(initialBalance), customer(cust) {}

void Account::deposit(double amount) {
    balance += amount;
    cout << "Deposit of $" << amount << " successful." << endl;
}

bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        cout << "Withdrawal of $" << amount << " successful." << endl;
        return true;
    } else {
        cout << "Error: Insufficient funds for withdrawal." << endl;
        return false;
    }
}

void Account::displayDetails() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: $" << balance << endl;
    cout << "Customer Details:" << endl;
    cout << "Name: " << customer->getName() << endl;
    cout << "Address: " << customer->getAddress() << endl;
    cout << "Contact Info: " << customer->getContactInfo() << endl;
}

Transaction::Transaction(int transID, double amt, Account* srcAccount, Account* destAccount)
    : transactionID(transID), amount(amt), sourceAccount(srcAccount), destinationAccount(destAccount) {}

void Transaction::executeTransaction() {
    if (sourceAccount->withdraw(amount)) {
        destinationAccount->deposit(amount);
        cout << "Transaction ID: " << transactionID << " - Transfer successful." << endl;
    } else {
        cout << "Transaction ID: " << transactionID << " - Transfer failed (insufficient funds)." << endl;
    }
}

void transferFunds(Account& source, Account& destination, double amount) {
    Transaction transaction(1, amount, &source, &destination);
    transaction.executeTransaction();
}

int main() {
    Customer customer1("John Doe", "123 Main St", "555-1234");
    Customer customer2("Jane Doe", "456 Oak St", "555-5678");

    Account account1(1001, 5000.0, &customer1);
    Account account2(1002, 3000.0, &customer2);

    cout << "Account 1 Details:" << endl;
    account1.displayDetails();
    cout << endl;

    cout << "Account 2 Details:" << endl;
    account2.displayDetails();
    cout << endl;

    account1.deposit(1000.0);
    account1.withdraw(2000.0);
    account1.displayDetails();
    cout << endl;

    account2.deposit(500.0);
    account2.withdraw(1000.0);
    account2.displayDetails();
    cout << endl;

    transferFunds(account1, account2, 1500.0);
    account1.displayDetails();
    account2.displayDetails();

    return 0;
}