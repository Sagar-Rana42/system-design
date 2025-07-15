#include<iostream>
#include<vector>
using namespace std;

// Abstract Base Class representing a general Bank Account
class Account {
public:
    // Pure virtual functions for deposit and withdraw
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;

    // Virtual destructor to avoid memory leaks when deleting derived objects via base class pointers
    virtual ~Account() {}
};

// Derived class for Saving Account
class SavingACC : public Account {
private:
    double currentBalance;

public:
    SavingACC() : currentBalance(0) {}

    void deposit(double amount) override {
        currentBalance += amount;
        cout << "Amount deposited in Saving Account. Balance is " << currentBalance << endl;
    }

    void withdraw(double amount) override {
        if (currentBalance - amount < 0) {
            cout << "Insufficient balance in Saving Account." << endl;
            return;
        }
        currentBalance -= amount;
        cout << amount << " withdrawn. Remaining balance in Saving Account is " << currentBalance << endl;
    }
};

// Derived class for Current Account
class CurrentACC : public Account {
private:
    double balance;

public:
    CurrentACC() : balance(0) {}

    void deposit(double amount) override {
        balance += amount;
        cout << amount << " deposited in Current Account. Balance is " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance - amount < 0) {
            cout << "Insufficient funds in Current Account." << endl;
            return;
        }
        balance -= amount;
        cout << amount << " withdrawn. Remaining balance in Current Account is " << balance << endl;
    }
};

// Derived class for Fixed Deposit Account
// This class violates the Liskov Substitution Principle (LSP)
class FixedDeposit : public Account {
private:
    double FDbalance;

public:
    FixedDeposit() : FDbalance(0) {}

    void deposit(double amount) override {
        FDbalance += amount;
        cout << amount << " deposited in Fixed Deposit Account. Balance is " << FDbalance << endl;
    }

    void withdraw(double amount) override {
        // Violates LSP by throwing exception instead of behaving like the base class
        throw runtime_error("Withdrawal not allowed from Fixed Deposit Account.");
    }
};

int main() {
    // Using base class pointers to achieve runtime polymorphism
    vector<Account*> accounts;

    accounts.push_back(new SavingACC());
    accounts.push_back(new CurrentACC());
    accounts.push_back(new FixedDeposit());

    cout << "\n--- Depositing Money ---\n";
    for (auto acc : accounts) {
        acc->deposit(500);
    }

    cout << "\n--- Withdrawing Money ---\n";
    for (auto acc : accounts) {
        try {
            acc->withdraw(300); // Will throw exception for FixedDeposit
        } catch (const exception& e) {
            // LSP violation detected: User of base class doesn't expect exceptions
            cout << "Error: " << e.what() << endl;
        }
    }

    // Clean up memory
    for (auto acc : accounts) {
        delete acc;
    }

    return 0;
}
