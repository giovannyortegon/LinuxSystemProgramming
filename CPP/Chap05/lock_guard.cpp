#include<iostream>
#include<mutex>
#include<thread>


struct ThreadInfo {
    std::mutex mutex;
    int counter;
};

void increment(ThreadInfo &info);

int main() {
    ThreadInfo thInfo;

    std::thread t1 (increment, std::ref(thInfo));
    std::thread t2 (increment, std::ref(thInfo));

    t1.join();
    t2.join();

    std::cout <<"Thread elaboration finished, Counter = " <<thInfo.counter <<std::endl;

    return (0);
}

void increment(ThreadInfo &info) {
    std::lock_guard<std::mutex> lock(info.mutex);
    std::cout <<"Threat Start ... " <<std::endl;

    for (int i = 0; i < 100000; ++i) {
        info.counter++;
    }

    std::cout <<"Threat Finished ... " <<std::endl;
}