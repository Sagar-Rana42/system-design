#include<iostream>
using namespace std;

// Example 1

/*
// ** Strategy Interface for wal ***** //
class WalkableRobot{
    public:
    virtual void walk()= 0;
    virtual ~WalkableRobot() {}
};

// **  Concrete Strategy for walk ** // 
class NormalWakl:public WalkableRobot{
    public:
    void walk() override{
        cout<<"Walking normally... "<<endl;
    }
};

class NoWalk : public WalkableRobot{
    public:
    void walk()override{
        cout<<"Cannot walk. "<<endl;
    }
};

// ** Stratgey Inteface for Talk  ** //
class TalkableRobot {
    public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {}
};

// concrete class for talkable 

class NormalTalk : public TalkableRobot{
    public:
    void talk() override{
        cout<<"Talking normally... "<<endl;
    }
};

class NoTalk : public TalkableRobot{
    public:
    void talk() override {
        cout<<"No Talking... "<<endl;
    }
};

// Robot Base Class -- 
class Robot{
    protected:
    WalkableRobot * walkBehave;
    TalkableRobot* talkBehave;

    public:
    Robot(WalkableRobot * walk , TalkableRobot* talk){
        this->walkBehave = walk;
        this->talkBehave = talk;
    }
    void walk(){
        walkBehave->walk();
    }
    void talk(){
        talkBehave->talk();
    }

    virtual void projection() = 0; // abstract method for subclass 

};

class CompanionRobot : public Robot{
    public:
    CompanionRobot(WalkableRobot * w , TalkableRobot* t): Robot(w,t) {}

    void projection() override {
        cout<<"Displaying friendly companion features... "<<endl;
    }
};
class WorkerRobot:public Robot{
    public:
    WorkerRobot(WalkableRobot * w ,TalkableRobot * t ) : Robot(w,t) {}

    void projection ()override{
        cout<<"Displaying worker efficiency stats..."<<endl;
    }
};


int main(){

    Robot* robot1 = new CompanionRobot(new NormalWakl , new NormalTalk());
    robot1->walk();
    robot1->talk();

    cout<<"--------------"<<endl;

    Robot* robot2 = new WorkerRobot(new NoWalk() , new NoTalk());
    robot2->walk();
    robot2->talk();
    robot2->projection();

    return 0;
}



*/


// Example 3 

// strategy Interface 

class PaymentStrategy{
    public:
    virtual void pay(int amount)  = 0;
    virtual ~PaymentStrategy() {}
};

// concrete Strategy 1 

class CreditCardPayment : public PaymentStrategy{
    public:

    void pay(int amount) override{
        if(amount <= 0){
            cout<<"Payment will must bigger by 1 "<<endl;
            return;
        }
        cout<<"paid "<<amount<<" using Credit Card. \n ";
    }

};

// concrete Strategy 2 
class PaypalPayment : public PaymentStrategy{
    public:
    void pay(int amount) override{
        if(amount <= 0){
            cout<<"Payment will must bigger by 1 "<<endl;
            return;
        }
        cout<<"paid "<<amount<<" using Paypal . \n ";
    }
};


class ShoppingCart{
    public:
    PaymentStrategy *p;

    ShoppingCart(PaymentStrategy *p){
        this->p = p;
    }

    void doPayment(int amount){
        if(p){
            p->pay(amount);
        }
        else{
            cout<<"can't be payment "<<endl;
        }
    }

};

int main(){
   
    
    CreditCardPayment  card;
    PaypalPayment  paypal;


    ShoppingCart *cart = new ShoppingCart(&card);
    cart->doPayment(500);

    ShoppingCart * cart1 = new ShoppingCart(&paypal);
    cart1->doPayment(100);
   
}