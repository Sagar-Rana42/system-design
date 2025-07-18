#include<iostream>
#include<vector>
using namespace std;

class Product{
    public:
    string name;
    double price;

    Product(string name, double price){
        this->name  = name;
        this->price = price;
    }
};


// violiting SRP: shoppingCart is handling multiple response
class ShoppingCart{
    private:
    vector<Product*>products;

    public:
    void addProduct(Product* p){
        products.push_back(p);
    }
    const vector<Product*> &getProuduct(){
        return products;
    }
    // 1: calculate total price in cart 
    double calculatePrice(){
        double price  = 0;
        for(auto p : products){
            price += p->price;
        }
        return price;
    }

    // 2: print invoice 
    void printInvoice(){
        cout<<"Shopping Cart Invoice: "<<endl;
        for(auto p : products){
            cout<<p->name<<" - $"<<p->price<<endl;
        }
        cout<<"Total: $"<<calculatePrice()<<endl;
        return;
    }

    // 3: store in DB
    void storeInDb(){
        cout<<"store in DB "<<endl;
        return;
    }

};

int main(){
    Product *p = new Product("cloth" , 500);
    Product *g = new Product("grocersy" , 5000);
    ShoppingCart * cart = new ShoppingCart();
    cart->addProduct(p);
    cart->addProduct(g);
   
    cart->getProuduct();
    cart->printInvoice();
}