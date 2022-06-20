#include<stddef.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<iostream>

int main(void) {
    pid_t child;
    int status;

    std::cout <<"I am the parent, My PID is " <<getpid() <<std::endl;
    std::cout <<"My Parent's PID is " <<getppid() <<std::endl;
    std::cout <<"I am going to create a new process..." <<std::endl;

    child = fork();
    if (child == -1) {
        // fork() return -1 on failure
        std::cout <<"fork() failed." <<std::endl;
        return (-1);
    } else if (child == 0) {
        std::cout <<"I am the child, my PID is " <<getpid() <<std::endl;
        std::cout <<"My parent's PID is " <<getppid() <<std::endl;
    } else {
        wait(&status);  // wait for the child process to finish
        std::cout <<"I am the parent, My PID is still " <<getpid() <<std::endl;
    }

    return (0);
}