#include<iostream>
using namespace std; 

class Animal{
    public:
    virtual void speak() = 0; // pure virtual . make Animal class abstract ;
    virtual ~Animal() = default;

};

class Dog : public Animal{
    public:
    void speak() override {
        cout<<"barking "<<endl;
    }
};

int main(){
    // Animal* a = new Animal(); // can't be create instance 

    Dog* d = new Dog();
    d->speak();

    Animal *a = new Dog(); /// by the help of polymorphism
    a->speak();


    return 0;
}

/*
Concept	               Behavior
virtual ~Animal()	 :-      Ensures correct destructor chain in polymorphism
Deleting derived object through Animal*	:-    Derived's destructor → Base's destructor
Multiple derived classes   :- 	Each has its own destructor chain; no impact on others
Without virtual destructor :- 	Only base destructor called ⇒ risk of memory leaks

*/