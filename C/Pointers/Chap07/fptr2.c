#include<stdio.h>
#include<malloc.h>

void mesg(int num) {
    printf("Mesg no. %d\n", num);
}

int main(int argc, char *argv[]) {
    int *t;
    void (*fpmsg1)(int);
    void (*fpmsg2)(int);

    fpmsg1 = mesg;
    fpmsg2 = mesg;

    fpmsg1(10);
    (*fpmsg2)(20);

    return (0);
}