#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<iostream>

using namespace std;

int main(void) {
    pid_t child;
    int status;

    cout <<"I am the parent, PID is " <<getpid() <<endl;
    cout <<"My parent's PID is " <<getppid() <<endl;
    cout <<"I am going to create a new process..." <<endl;

    child = fork();
    if (child == -1) {
        // fork() return -1 on failure
        cout <<"fork() failed." <<endl;

        return (-1);
    } else if (child == 0) {
        if (execl("/usr/bin/ls", "ls", "-l", NULL) < 0) {
            cout <<"execl failed." <<endl;
            return (2);
        }

        cout << "I am the child, my PID is " <<getpid() <<endl;
        cout <<"My parent's PID is " <<getppid() <<endl;
    } else {
        wait(&status);
    }

    return (0);
}