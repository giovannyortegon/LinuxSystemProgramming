#include<stdio.h>
#include<unistd.h>

int main() {
    int pid = fork();

    if (pid > 0) {
        printf("Parent Process is created.\n");
    } else {
        printf("Child process is Created.\n");
    }

    return (0);
}