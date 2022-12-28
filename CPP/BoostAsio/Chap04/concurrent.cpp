#include<iostream>
#include<boost/thread.hpp>
#include<boost/chrono.hpp>

void Print1(void);
void Print2(void);

int main(void) {
    boost::thread_group threads;

    threads.create_thread(Print1);
    threads.create_thread(Print2);

    threads.join_all();

    return(0);
}

void Print1(void) {
    for (int i = 0; i < 5; i++) {
        boost::this_thread::sleep_for(boost::chrono::milliseconds{500});
        std::cout <<"[Print1] Line: " <<i <<"\n";
    }
}

void Print2(void) {
    for (int i = 0; i < 5; i++) {
        boost::this_thread::sleep_for(boost::chrono::milliseconds{500});
        std::cout <<"[Print2] Line: " <<i <<"\n";
    }
}