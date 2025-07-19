#include<iostream>
using namespace std;

// Abstraction
class IInputDevice {
public:
    virtual string getInput() = 0;
    virtual ~IInputDevice() = default;
};

// Low-level modules
class Keyboard : public IInputDevice {
public:
    string getInput() override {
        return "Keyboard input";
    }
};

class TouchScreen : public IInputDevice {
public:
    string getInput() override {
        return "Touch input";
    }
};

// High-level module depends on abstraction
class Computer {
    IInputDevice* inputDevice;
public:
    Computer(IInputDevice* device) : inputDevice(device) {}
    
    void input() {
        cout<< inputDevice->getInput() << endl;
    }
};


int main() {
    Keyboard keyboard;
    TouchScreen touch;

    Computer comp1(&keyboard);
    comp1.input();  // Output: Keyboard input

    Computer comp2(&touch);
    comp2.input();  // Output: Touch input

    return 0;
}

