#include<stdio.h>
#include<unistd.h>

int main() {
    char dir[75];
    printf("Current working directory is %s\n", getcwd(dir, 75));

    return (0);
}