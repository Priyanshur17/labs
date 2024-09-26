

class BankAccount {
private:
    double balance;

public:
    // Constructor
    BankAccount();

    // Member functions
    double getBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
};

