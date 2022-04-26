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

    cout <<"I am the parent, my PID is " <<getpid() <<endl;

    child = fork();

    cout <<"Forked a child process with PID = " <<child <<endl;

    if (child == -1) {
        cout <<"fork() failed." <<endl;
        return (1);
    } else if (child == 0) {
        cout <<"About to run the child process with PID = " <<child <<endl;

        if (execl("./child.out", "child.out", NULL)) {
            cout <<"Error in executing child process " <<endl;
        }
    } else {
        cout <<"Killing the child process with PID = " <<child <<endl;
        int status = kill(child, 9);
        if (status == 0) {
            cout <<"chiild process killed ..." <<endl;
        } else {
            cout <<"There was a problem killing the process with PID = " <<child <<endl;
        }
    }

    return (0);
}