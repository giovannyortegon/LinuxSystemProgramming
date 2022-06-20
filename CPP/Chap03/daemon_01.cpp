#include<unistd.h>
#include<sys/stat.h>
#include<iostream>

using namespace std;

int main(void) {
    pid_t child;
    int status;

    cout <<"I am the parent, my PID is " <<getpid() <<endl;
    cout <<"I am going to create a new daemon process..." <<endl;
    // i. clear file creation mask
    umask(0);

    child = fork();
    if (child == -1) {
        cout <<"fork() failed." <<endl;
        return (-1);
    } else if (child == 0) {
        setsid();
        if (chdir("/") < 0) {
            cout <<"Couldn't change directory" <<endl;
        }
        sleep(10);
    }

    return (0);
}