#include<iostream>
using namespace std;

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