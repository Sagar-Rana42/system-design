#include<iostream>
#include<vector>
using namespace std;

class Product{
    public:
    string name;
    double price ;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart{
    private:
    vector<Product*>products;

    public:
    void addProduct(Product* prod){
        products.push_back(prod);
    }
    virtual ~ShoppingCart(){
        for(auto p: products){
            // delete all products also
            delete p;
        }
        cout<<"delete cart "<<endl;
    }

    vector<Product*>getProducts(){
        return products;
    }

    double totalPrice(){
        double total = 0;
        for(auto prod :products){
            total += prod->price;
        }
        return total;
    }


};
class PrintInvoice{
    private:
    ShoppingCart * cart;
    public:
    PrintInvoice(ShoppingCart* cart){
        this->cart = cart;
    }
    virtual ~PrintInvoice(){
        cout<<"deleteing invoice "<<endl;
    }
    
    void printInvoice(){
        vector<Product*>products = cart->getProducts();
        cout<<"Priniting Invoice "<<endl<<endl;
        for(auto prod : products){
            cout<<prod->name<<" - "<<prod->price<<endl;
        }
    }

};

class saveToDB{
    // this will abstract  virtual class 
    public:
    virtual void saveInDB() = 0; // this is pure virtual function , mean to be overriden
    virtual ~saveToDB() = default;
};
class saveInSQL : public saveToDB{
    private :
    ShoppingCart * cart;
    public:

    saveInSQL(ShoppingCart* cart){
        this->cart  = cart;
    }
    ~saveInSQL(){
        cout<<"deleting saveIN SQL method "<<endl;
    }
    void saveInDB() override {
        cout<<"Data save in SQL "<<endl;
    }

};

class saveInMongoDB : public saveToDB{
    public:

    ShoppingCart *cart ;
    saveInMongoDB(ShoppingCart* cart ){
        this->cart = cart;
    }
    void saveInDB() override {
        cout<<"data is save in MONGODB "<<endl;
    }
};
int main(){

    ShoppingCart * cart = new ShoppingCart();
    cart->addProduct(new Product("fruit" , 500));
    cart->addProduct(new Product("vegetable" , 30.60));

    PrintInvoice* printer = new PrintInvoice(cart);
    printer->printInvoice();

    saveInSQL *saveSql = new saveInSQL(cart);
    saveSql->saveInDB();
   cout<<"Total price = "<< cart->totalPrice()<<endl;


   delete saveSql;
   delete printer;
   delete cart;

    return 0;
}