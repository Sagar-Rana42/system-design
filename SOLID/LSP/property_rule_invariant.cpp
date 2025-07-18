#include<iostream>
using namespace std;


// class Invariant of a parent class oject should not be broken by  child class object .
//  child class can either maintain or strengthen the invariant but never narrows it down.

// invariant for this account is : balance can't be negative 
class Account{
    public:
    double balance ;

    Account(double balance) {
        if(balance < 0){
            throw invalid_argument("Balance can't be negative");
        }
        else{
            this->balance= balance;
        }
    }
    virtual void withdraw(double amount){
        if(balance-amount < 0){
            throw runtime_error("Insufficient funds");
        }else{
            balance -= amount;
            cout<<"amount withdrawn. Remaining balance is "<<balance<<endl;
        }
    }

};

class cheatAccount : public Account{

    public:
    cheatAccount(double b):Account(b){}

    // use condition check for follow LSP 
    void withdraw(double amount) override{
        balance -= amount; // LSP will break , because balance may be in negative
        cout<<"Amount withdrawn. Remaining balance is "<<balance<<endl;
    }
    
};

int main(){
    Account *acc = new Account(500);
    acc->withdraw(5000);

    // cheatAccount *cacc= new cheatAccount(800);
    // cacc->withdraw(5222);

  

    return 0;
}