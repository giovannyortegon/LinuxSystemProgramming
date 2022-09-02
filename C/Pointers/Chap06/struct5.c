#include<stdio.h>
#include<stdlib.h>

int main() {
    struct data {
        int i;
        char c;
        int j;
    };

    struct data v1;
    struct data * dsptr;
    printf("Size of structure data: %ld\n", sizeof(struct data));
    dsptr = (struct data *)malloc(sizeof(struct data));

    printf("Address of member int i = %u\n", &(dsptr->i));
    printf("Address of member char c = %u\n", &(dsptr->c));
    printf("Address of member int j = %u\n", &(dsptr->j));

    return (0);
}