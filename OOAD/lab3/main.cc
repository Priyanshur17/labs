// main.cpp
#include <iostream>
#include "BankAccount.h"
using namespace std;
int main() {
    BankAccount account;

    account.deposit(1000.0);

    cout << "Current Balance: $" << account.getBalance() << endl;

    account.withdraw(500.0);

    cout << "Updated Balance: $" << account.getBalance() << endl;

    return 0;
}


//g++ -o myBankApp BankAccount.cc main.cc