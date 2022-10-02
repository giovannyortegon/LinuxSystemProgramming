#include<stdio.h>

int main(int argc, char *argv[]) {
    extern char ** environ;
    char **environment_list = environ;
    int i = 1;

    while(* environment_list != NULL) {
        printf("%d - %s\n",i, *environment_list);
        environment_list++;
        i++;
    }

    return (0);
}