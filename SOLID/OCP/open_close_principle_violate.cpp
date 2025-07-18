#include<iostream>
#include<vector>
using namespace std;

//  class for products 

class Product{
    public:
    string name;
    double price;

    Product(string name , double price){
        this->name = name;
        this->price=  price;
    }

    virtual ~Product() = default;

    
};

// class  for shoping cart 
class ShoppingCart{
    private:
    vector<Product*>products;
    public:
    void addProduct(Product* p){
        products.push_back(p);
    }
    vector<Product*>getProduct(){
        return products;
    }

    double totalPrice(){
        double total = 0;
        for(auto prod : products){
            total += prod->price;
        }
        return total;
    }


};

// class for print receipt 

class ShoppingCartPrinter{
    
    private:
    ShoppingCart* cart;

    public:
    ShoppingCartPrinter(ShoppingCart * cart){
        this->cart = cart;
    }
    
    void printReceipt(){

        // vector<Product*>products = cart->getProduct();
        for(auto prod : cart->getProduct()){
            cout<<prod->name<<" - "<< prod->price<<endl;
        }
    }
};
class saveTODB{
    private:
    ShoppingCart* cart;
    public:
    saveTODB(ShoppingCart* cart){
        this->cart = cart;
    }

    /*
    If tomorrow we want to save in Firebase, PostgreSQL, or local file:

    we'll have to modify this class and add more methods.
    This violates the OCP.
    */



    void saveinSQL(){
        cout<<"Data save in SQL "<<endl;
    }
    void saveinMONGO(){
        cout<<"data Save in mongoDB "<<endl;
    }


};


int main(){

    ShoppingCart * cart = new ShoppingCart();
    cart->addProduct(new Product("apple" , 20));
    cart->addProduct(new Product("mango" , 50));

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printReceipt();
    saveTODB* saveDB = new saveTODB(cart);
    saveDB->saveinMONGO();


    delete cart;
    delete printer;
    delete saveDB;

    return 0;
}