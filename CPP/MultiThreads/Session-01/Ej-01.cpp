#include<iostream>
#include<thread>

void myFunc() {
    std::cout <<"So, are we thre yet? " <<std::endl;
}

int main() {
    // myFunc();

    std::thread t1(myFunc);


    t1.detach();

    t1.join();

    return (0);
}