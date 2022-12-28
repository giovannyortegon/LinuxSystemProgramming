#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void raiseAlarm(int sig);

int main() {
    alarm(5);
    signal(SIGALRM, raiseAlarm);

    while (1) {
        printf("Hello World!.\n");
        sleep(1);
    }

    return(0);
}

void raiseAlarm(int sig) {
    printf("The alarm has Raised.\n");
    exit(0);
}