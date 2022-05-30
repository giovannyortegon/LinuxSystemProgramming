#include<stdio.h>
#include<stdlib.h>

void calling_function(void);
int * called_function(int * x);

int main(void) {
    calling_function();
    return (0);
}

void calling_function(void) {
    int t1;
    int * t2;

    t1 = 10;
    t2 = called_function(&t1);

    printf("Suma: %d\n", *t2);

    free(t2);
}

int * called_function(int * x) {
    int t2;
    int * t1;
    int * t3;

    t1 = x;
    t2 = 10;

    t3 = (int *) malloc(sizeof(int));
    *t3 = *t1 + t2;

    return (t3);
}
