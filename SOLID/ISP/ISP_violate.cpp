#include<iostream>
#include<stdexcept>
using namespace std;

// General interface combining unrelated functionalities (Violation of ISP)
class WorkAndEat {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
};

/*
 * Human class needs both work() and eat(),
 * so it makes sense to implement both.
 */
class Human : public WorkAndEat {
public:
    void work() override {
        cout << "Human is doing work." << endl;
    }

    void eat() override {
        cout << "Human is eating." << endl;
    }
};

/*
 * Robot class only needs to work, not eat.
 * But due to ISP violation (common interface forces eat()), 
 * we are forced to implement eat() unnecessarily.
 */
class Robot : public WorkAndEat {
public:
    void work() override {
        cout << "Robot is doing work." << endl;
    }

    // This function is irrelevant for Robot, but we must implement it
    void eat() override {
        throw logic_error("Robots do not eat!");
    }
};

int main() {
    Human* h = new Human();
    h->work();
    h->eat();

    Robot* robo = new Robot();
    robo->work();

    // Below call will throw an exception due to ISP violation
    try {
        robo->eat();
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    delete h;
    delete robo;

    return 0;
}
