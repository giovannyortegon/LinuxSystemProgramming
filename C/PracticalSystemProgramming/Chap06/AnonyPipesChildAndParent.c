#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

#define BUFFER_SIZE 1024

int pipefds[2];
int status, pid;
char writemessage[BUFFER_SIZE];
char readmessage[BUFFER_SIZE];

void pipeOperation();

int main() {
    status = pipe(pipefds);
    if (status == -1) {
        printf("Unable to create pipe.\n");
        return (1);
    }

    printf("Enter the message to write into Pipe\n");
    printf("To exit type \"quit\"\n");

    fgets(writemessage, BUFFER_SIZE, stdin);

    while(strcmp(writemessage, "quit\n") != 0) {
        pipeOperation();
        fgets(writemessage, BUFFER_SIZE, stdin);
        kill(pid, SIGKILL);
    }

    return (0);
}

void pipeOperation() {
    pid = fork();

    // Child Process to Read the Data.
    if(pid == 0) {
        read(pipefds[0], readmessage, sizeof(readmessage));
        printf("Child Process: Writing to pipe - Message is %s", writemessage);
        write(pipefds[1], writemessage, sizeof(writemessage));
    } else {
        printf("Parent Process: Writing to pipe - Message is %s", writemessage);
        write(pipefds[1], writemessage, sizeof(writemessage));
    }
}
