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

    std::cout <<"Unique_lock:: Threads elaborate finished. Counter = " <<thInfo.counter <<std::endl;

    return (0);
}

void increment(ThreadInfo &info) {
    std::unique_lock<std::mutex> lock(info.mutex);
    std::cout <<"Thread Start ... " <<std::endl;

    for (int i = 0; i < 100000; ++i) {
        info.counter++;
    }

    std::cout <<"unique_lock:: Thread Finished ... " <<std::endl;
}