#include<iostream>
using namespace std;

class saveToDB{

    public:
    
    // they are violiting the open- close principle 
    void saveInDb(string str){
        if(str == "mongoDB"){
            cout<<"data save to mongoDB "<<endl;
        }
        else if(str == "SQL"){
            cout<<"data save to SQL "<<endl;
        }
        else{
            cout<<"failed to save data "<<endl;
        }
    }
    

   


};

int main(){

    saveToDB* storage = new saveToDB();

    storage->saveInDb("SQL");
    storage->saveInDb("mongoDB");

    return 0;
}