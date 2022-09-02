#include<stdio.h>

struct inner_node {
    int int_a;
    int int_b;
};

struct node {
    int * a;
    int * b;
    struct inner_node * in_node;
};

int main() {
    struct node * p;
    int * arrptr;
    int arr[10];

    arrptr = arr;

    printf("Size of pointer variable (struct node *) = %ld\n", sizeof(struct node *));
    printf("Size of pointer variable pointing to int array = %ld\n", sizeof(arrptr));

    return (0);
}