#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void * customeThreadFunction() {
    printf("This is my custom Thread.\n");
    return (NULL);
}

int main() {
    pthread_t thread1, thread2;
    int status;

    pthread_create(&thread1, NULL, customeThreadFunction, NULL);
    pthread_create(&thread2, NULL, customeThreadFunction, NULL);

    if (pthread_equal(thread1, thread2)) {
        fprintf(stdout, "Two threads are equals.\n");
    } else {
        fprintf(stderr, "Two thread are not equals.\n");
        return (0);
    }

    for (int i = 0; i < 15; i++) {
        printf("I am the process created by compiler by default.\n");
        sleep(1);
    }

    return (0);
}