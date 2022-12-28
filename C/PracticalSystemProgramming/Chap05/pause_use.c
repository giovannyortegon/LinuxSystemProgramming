#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void SIGNAL_HANDLER(int);

int main(void) {
    alarm(10);
    signal(SIGALRM, SIGNAL_HANDLER);

    if (alarm(7) > 0) {
        printf("An alarm has been set already.\n");
    }

    pause();

    printf("You will not see this text.\n");

    return (1);
}
void SIGNAL_HANDLER(int signo) {
    printf("Caught the signal with number: %d\n", signo);
    exit(0);
}