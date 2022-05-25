#include<pthread.h>
#include<semaphore.h>
#include<iostream>

struct ThreadInfo {
    sem_t sem;
    int countier;
};

void * increment(void * arg) {
    ThreadInfo * info = static_cast<ThreadInfo *> (arg);
    sem_wait(&info->sem);

    std::cout <<"Thread Start ... " <<std::endl;

    for (int i = 0; i < 100000; ++i) {
        info->countier++;
    }

    std::cout <<"Thread finish ... " <<std::endl;
    sem_post(&info->sem);

    return nullptr;
}

int main() {
    ThreadInfo thInfo;

    thInfo.countier = 0;
    if (sem_init(&thInfo.sem, 0, 1) != 0) {
        std::cout <<"sem_init failed!!" <<std::endl;

        return (1);
    }

    pthread_t t1;
    if (pthread_create(&t1, nullptr, &increment, &thInfo) != 0) {
        std::cout <<"pthread_create for t1 failed! " <<std::endl;

        return (2);
    }

    pthread_t t2;

    if(pthread_create(&t2, nullptr, &increment, &thInfo) != 0) {
        std::cout <<"pthread_create for t2 failed!! " <<std::endl;

        return (3);
    }

    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

    std::cout <<"Posix Semaphore::  Thread elaboration finished, counter = "
              <<thInfo.countier <<std::endl;


    sem_destroy(&thInfo.sem);

    return (0);
}