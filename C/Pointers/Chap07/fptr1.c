#include<stdio.h>
#include<malloc.h>

void mesg(int num) {
    printf("Mesg no. %d\n", num);
}

int * add(int x, int y) {
    int * z = (int *)malloc(sizeof(int));
    *z = 10;

    return (z);
}

int main(int argc, char *argv[]) {
    int *t;
    void (*fpmsg)(int);
    int * (*addptr)(int, int);
    addptr = &add;
    fpmsg = mesg;

    fpmsg(10);
    t = addptr(19, 11);

    return (0);
}