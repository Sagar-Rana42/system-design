#include<iostream>
#include<stdexcept>
using namespace std;

// General interface combining unrelated functionalities (Violation of ISP)

/*
class WorkAndEat {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
};

*/
class Work{
    public:
    virtual void work() = 0;
};
class Eat{
    public:
    virtual void eat() =0;
};

class Human : public Work , public Eat {
public:
    void work() override {
        cout << "Human is doing work." << endl;
    }

    void eat() override {
        cout << "Human is eating." << endl;
    }
};


class Robot : public Work {
public:
    void work() override {
        cout << "Robot is doing work." << endl;
    }

    
    
};

int main() {
    Human* h = new Human();
    h->work();
    h->eat();

    Robot* robo = new Robot();
    robo->work();

    

    delete h;
    delete robo;

    return 0;
}
