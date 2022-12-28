#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define BUFFER_SIZE 1024

// Global Variables
int pipefds[2];
int status;
char writemessage[BUFFER_SIZE];
char readmessage[BUFFER_SIZE];

// pipe Operation to perform read and write Operation
void pipeOperation();

int main() {
    status = pipe(pipefds);

    if (status == -1) {
        printf("Unable to create pipe\n");
        return -1;        
    }

    printf("Enter the message to write into Pipe\n");
    printf("To exit type \"quit\"\n");

    fgets(writemessage, BUFFER_SIZE, stdin);
    // This loop is used to take continuous standart input.
    while (strcmp(writemessage, "quite\n")) {
        pipeOperation();
        fgets(writemessage, BUFFER_SIZE, stdin);
    }

    close(pipefds[0]); 
    close(pipefds[1]); 

    return (0);
}

void pipeOperation() {
    printf("Writing to pipe - Message is %s", writemessage);
    write(pipefds[1], writemessage, sizeof(writemessage));
    read(pipefds[0], readmessage, sizeof(readmessage));
    printf("Reading from pipe - Message is %s", readmessage);
}