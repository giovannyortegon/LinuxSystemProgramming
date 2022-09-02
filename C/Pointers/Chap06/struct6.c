#include<stdio.h>
#include<stdlib.h>

int main() {
    struct data {
        int i;
        char c1;
        int j;
        char c2;
        int k;
    };

    struct data v1;
    struct data * dsptr;
    printf("Size of structure data: %ld\n", sizeof(struct data));
    dsptr = (struct data *)malloc(sizeof(struct data));

    printf("Address of member int i = %u\n", &(dsptr->i));
    printf("Address of member char c1 = %u\n", &(dsptr->c1));
    printf("Address of member int j = %u\n", &(dsptr->j));
    printf("Address of member char c2 = %u\n", &(dsptr->c2));
    printf("Address of member int j = %u\n", &(dsptr->k));

    return (0);
}