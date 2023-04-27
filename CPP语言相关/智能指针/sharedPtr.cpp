#include<iostream>
#include<mutex>
#include<thread>
#include<memory>
#include<chrono>
struct Base{
    Base(){
        std::cout<< "  Base::Base()\n";
    }
    ~Base(){
        std::cout<<"  Base::~Base()\n";
    }
};
struct Derived: public Base{
    Derived(){
        std::cout<<"    Derived::Derived()\n";
    }
    ~Derived(){
        std::cout<<"    Derived::~Derived()\n";
    }
};
void thr(std::shared_ptr<Base> p){
    std::this_thread::sleep_for(std::chrono::seconds(1));
}