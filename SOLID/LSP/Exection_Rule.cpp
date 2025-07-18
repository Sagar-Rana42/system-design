#include<iostream>
using namespace std;

// +++++++++++++++++++++++++++   Exception Rule :-  
/*

std::logic_error :- for logical errors detected before runtime 
   - std::invalid_argument 
   - std::domain_error
   - std::length_error
   - std::ot_of_range


std::runtime_error
    - std::range_error
    - std::overflow_error
    - std::underflow_error
*/

class Parent{
    public:
    virtual void getValue() noexcept(false) { // it will throw logic_error exception 
        throw logic_error("parent error");
    }

    /* Meaning:

        noexcept(false) tells the compiler that this function may throw exceptions.

        It is explicitly stating: “I might throw.”

        Compare:
        noexcept(true) or just noexcept → Function promises NOT to throw.

        noexcept(false) → Function may throw, and it's allowed to.

    */
};



class Child : public Parent{

    public:
    void getValue() noexcept(false) override{
        throw out_of_range("child error");
    }
};

class client{
    private:
    Parent *p;

    public:
    client(Parent* p){
        this->p  = p;
    }
    void takeValue(){
        try{
            p->getValue();

        }
        catch(const logic_error& e)
        {
            cout<<"logical error occur happen : " << e.what() << '\n';
        }
        
    }
};
int main(){
    Parent *p = new Parent();
    Child *c  = new Child();


    client * cli = new client(c);
    cli->takeValue();
    return 0;
}