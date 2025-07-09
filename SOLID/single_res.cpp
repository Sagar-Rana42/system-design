#include<iostream>
#include<vector>
using namespace std;

// product class representing only eCommerce product 
class Product{
    public:
    double price;
    string name;

    Product(string name, int price){
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart{
    public:

    vector<Product*>products;

    void addItem(Product *p){
        products.push_back(p);
    }
    vector<Product*>getProduct(){
        return products;
    }
    double calculatePrice(){
        double price = 0;
        for(auto prod : products){
            price += prod->price;
        }
        return price;
    }
};

class ShoppingCardPrinter{
    private:
    ShoppingCart * cart;

    public:
    ShoppingCardPrinter(ShoppingCart* cart){
        this->cart = cart;
    }
    void printInvoice(){
        cout<<"Shoppping Card Invoice:\n"<<endl;
        for(auto prod : cart->products){
            cout<<prod->name<<"  "<<prod->price<<endl;
        }
        cout<<"total = "<<cart->calculatePrice()<<endl;
    }
   
};

class StoreInDB{
    private:
    ShoppingCart * cart;
    public:

    StoreInDB(ShoppingCart * cart){
        this->cart = cart;
    }
    void store(){
        cout<<"getting store in database "<<endl;
    }
};

int main(){
    ShoppingCart *cart = new ShoppingCart();
    ShoppingCardPrinter * printer = new ShoppingCardPrinter(cart);

    Product *p1 = new Product("rice",200);
    Product *p2 = new Product("r3",20);
    cart->addItem(p1);
    cart->addItem(p2);
    printer->printInvoice();

    StoreInDB * st = new StoreInDB(cart);
    st->store();
    
    return 0;
}