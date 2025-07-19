#include<iostream>
using namespace std;

class Keyboard{
    public:

    string getInput(){
        return "keyboard  input";
    }
};
class Computer{
    public:
    Keyboard keyboard;

    public:
    void getInput(){
        cout<<keyboard.getInput();
    }
};

int main(){

    Computer com;
    com.getInput();

    /*
    
    *. Computer directly depend on concrete class 
    *. Changing to touchScreen or voiceInput required modifying in computer
    
    */

    return 0;
}