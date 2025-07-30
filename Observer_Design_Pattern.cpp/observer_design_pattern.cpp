#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class ISubscriber{
    public:
    virtual void update() = 0;
    virtual ~ISubscriber() {}
};

// Abstract Observable interface : a Youtube channel interface 
class IChannel {
    public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notifySubscriber() = 0;

    virtual ~IChannel() {}
};

// Concrete Subject : a youtube channel that observers can subscribe to 
class Channel : public IChannel{
    private:
    vector<ISubscriber*>subscribers; /// list of subscribers 
    string name;
    string latestVideo;

    public:
    Channel(const string &name){
        this->name = name;
    }


    // add a subscriber (avoid duplicates)
    void subscribe(ISubscriber* subscriber) override {
        if(find(subscribers.begin() , subscribers.end() , subscriber) == subscribers.end()){
            subscribers.push_back(subscriber);
        }
    }

    // Remove a subscriber if present 

    void unsubscribe(ISubscriber * subscriber ) override{
        auto it = find(subscribers.begin() , subscribers.end() , subscriber);
        subscribers.erase(it);
        cout<<"got unsubscribe "<<endl;
    }

    void notifySubscriber()override {
        for(auto sub : subscribers){
            sub->update();
        }
    }
    void uploadVideo(string title){
        latestVideo = title;
        cout<< "\n["<<name<<" uploaded \""<<title<<"\"]\n";
        notifySubscriber();

    }
    // read video data 
    string getVideoData(){
        return "\nCheckout our new video: " + latestVideo +"\n";
    }
};

// concerte Observer : represent a subscriber to the channel

class Subscriber : public ISubscriber {
    private:
    string name;
    Channel * channel;

    public:
    Subscriber(string name , Channel* channel){
        this->name = name;
        this->channel = channel;
    }

    // called by channel : print notification message 
    void update() override{
        cout<<"Hey "<<name<<","<<this->channel->getVideoData();
    }
};


int main(){

    Channel* channel1 = new Channel("@sagar");

    Subscriber* subs1 = new Subscriber("sagar" , channel1);
    Subscriber* subs2 = new Subscriber("rana" , channel1);

    channel1->subscribe(subs1);
    channel1->subscribe(subs2);

    // upload a video : both carun and tarun are notified 
    channel1->uploadVideo("complete guide for next.js");

    channel1->unsubscribe(subs1);

    // upload another video : 
    channel1->uploadVideo("full stack project summary");

    return 0;
}