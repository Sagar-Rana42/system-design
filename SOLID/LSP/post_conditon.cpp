#include<iostream>
using namespace std;

class Car{
    public: 
    virtual void brake(){
        cout<<"car slow "<<endl;
    }
};

class electric:public Car{
    public:
    virtual void brake() override{
        cout<<"Car slow and charging happen due to brake apply "<<endl;
    }
};
int main(){
    Car *c = new electric();
    c->brake();

}