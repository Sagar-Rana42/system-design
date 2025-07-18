#include<iostream>
using namespace std;

class Bird{
    public:
    virtual void fly(int height){
        cout<<"Bird fly on "<<height<<" M height "<<endl;
        
    }
};

class penguin : public Bird{

    public:
    // strengthen the base class ,     VIOLATING LSP 
    virtual void fly(int height){
        if(height > 0)throw runtime_error("Height must be 0 ");
    }


};

int main(){
    Bird *b  = new Bird();

    b->fly(20);

    penguin* p = new penguin();
    p->fly(10); // violating LSP: by provide strength to base class 

    return 0;

}