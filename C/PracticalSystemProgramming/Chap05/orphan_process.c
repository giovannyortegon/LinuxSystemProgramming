#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main() {
    pid_t child_pid = fork();

    // parent process
    if (child_pid > 0) {
        printf("In parent Process!\n");
    } else {
        printf("In child process.!\n");
        // making the child process to sleep for some time.
        sleep(10);
        printf("After sleep time.\n");
    }

    return (0);
}