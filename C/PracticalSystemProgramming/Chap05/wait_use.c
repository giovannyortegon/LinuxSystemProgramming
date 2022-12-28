#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {

    int status = fork();

    if (status == 0) {
        printf("Hello from child.\n");
        printf("Child work is Completed and terminating.!\n");
    } else {
        printf("Hello from parent.\n");
        wait(&status);
        printf("Parent has terminated.\n");
    }

    return (0);
}