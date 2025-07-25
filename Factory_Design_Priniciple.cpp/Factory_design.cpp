#include<iostream>
using namespace std;

// step1 : create an interface 
class Shape{
    public:
    virtual void draw() = 0;
};

// create concrete implementations
class Circle : public Shape{
    public:
    void draw() override {
        cout<<"Drawing circle "<<endl;
    }
};
class Square : public Shape{
    public:
    void draw() override{
        cout<<"Drawing square "<<endl;
    }

};


// Create Factory Function 

class ShapeFactory{
    public:
   static Shape* getShape(string type){
        if(type == "circle") return new Circle();
        if(type == "square") return new Square();
        return nullptr;
    }
};

// client 

int main(){
    Shape * circle = ShapeFactory::getShape("circle");
    circle->draw();

    Shape* square = ShapeFactory::getShape("square");
    square->draw();
    return 0;
}