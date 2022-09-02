#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * customeThreadFunction() {
    for(int i = 0; i < 15; i++){
        printf("I am a Custom Thread function Created by parameters.\n");
        sleep(1);
    }
    return (NULL);
}

int main() {
    pthread_t thread;
    int status;

    status = pthread_create(&thread, NULL, customeThreadFunction, NULL);

    if (!status) {
        fprintf(stdout, "Custom Created Successfully.\n");
    } else {
        fprintf(stderr, "Unable to create the custome Thread.\n");
        return (0);
    }

    for (int i = 0; i < 15; i++) {
        printf("I am the process created by compiler by default.\n");
        sleep(1);
    }

    return (0);
}