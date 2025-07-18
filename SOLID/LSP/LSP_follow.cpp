#include<iostream>
#include<vector>
using namespace std;

// Interface for accounts that support deposit
class DepositableAccount {
public:
    virtual void deposit(double amount) = 0;
    virtual ~DepositableAccount() {}
};

// Interface for accounts that support withdrawal
class WithdrawableAccount {
    public:
    virtual void withdraw(double amount) = 0;
    virtual ~WithdrawableAccount() {}
};

// General account type: supports both deposit and withdraw
class GeneralAccount : public DepositableAccount, public WithdrawableAccount {
    // This interface can be used if both behaviors are required
};

// =====================
// Saving Account
// =====================
// Supports both deposit and withdraw → inherits GeneralAccount
class SavingAcc : public GeneralAccount {
private:
    double balance;

public:
    SavingAcc() : balance(0) {}

    void deposit(double amount) override {
        balance += amount;
        cout << amount << " deposited in Saving Account. Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance - amount < 0) {
            cout << "Insufficient balance in Saving Account." << endl;
            return;
        }
        balance -= amount;
        cout << amount << " withdrawn from Saving Account. Remaining balance: " << balance << endl;
    }
};

// =====================
// Fixed Deposit Account
// =====================
// Only supports deposit, not withdrawal → only inherit DepositableAccount
class FixedAcc : public DepositableAccount {
private:
    double balance;

public:
    FixedAcc() : balance(0) {}

    void deposit(double amount) override {
        balance += amount;
        cout << amount << " deposited in Fixed Deposit Account. Balance: " << balance << endl;
    }

    // ⚠ No withdraw method here
    // This design avoids violating LSP
};

// =====================
// Current Account
// =====================
// Supports both deposit and withdraw → inherits GeneralAccount
class CurrentAcc : public GeneralAccount {
private:
    double balance;

public:
    CurrentAcc() : balance(0) {}

    void deposit(double amount) override {
        balance += amount;
        cout << amount << " deposited in Current Account. Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance - amount < 0) {
            cout << "Insufficient funds in Current Account." << endl;
            return;
        }
        balance -= amount;
        cout << amount << " withdrawn from Current Account. Remaining balance: " << balance << endl;
    }
};

class Client{
    public:
    vector<GeneralAccount*>generalAcc;
    vector<DepositableAccount*>depositAcc;

    Client(vector<GeneralAccount*>generalAcc , vector<DepositableAccount*>depositAcc){
        this->generalAcc = generalAcc;
        this->depositAcc = depositAcc;
    }

    void transaction(){
        for(GeneralAccount* cls : generalAcc){
            cls->deposit(2000);
            cls->withdraw(400);
        }
        for(DepositableAccount* cls : depositAcc){
            cls->deposit(500);
        }
    }
};

int main() {

    /*
    // Using polymorphism to call appropriate methods

    // Saving Account: supports both deposit and withdraw
    GeneralAccount* saving = new SavingAcc();
    saving->deposit(1000);
    saving->withdraw(500);

    cout << endl;

    // Fixed Deposit Account: only deposit supported
    DepositableAccount* fixed = new FixedAcc();
    fixed->deposit(2000);
    //  Withdraw not allowed – not even in the interface

    cout << endl;

    // Current Account: supports both deposit and withdraw
    GeneralAccount* current = new CurrentAcc();
    current->deposit(1500);
    current->withdraw(1800); // Should show insufficient funds

    // Clean up memory
    delete saving;
    delete fixed;
    delete current;
*/

    
    vector<GeneralAccount*>generalAcc;
    vector<DepositableAccount*>depositAcc;

    SavingAcc* savingAccount = new SavingAcc();
    CurrentAcc* CurrentAccount = new CurrentAcc();

    generalAcc.push_back(savingAccount);
    generalAcc.push_back(CurrentAccount);


    FixedAcc* fx = new FixedAcc();
    depositAcc.push_back(fx);

    Client* cli = new Client(generalAcc , depositAcc);

    cli->transaction();



    return 0;
}
