#include<stdio.h>
#include<stdlib.h>

typedef struct Numbers {
    int a;
    int b;
} numbers;

void setNumbers(numbers * n);
numbers * setNumbers_2();


int main() {
    int a, b;

    numbers setNumber = {2, 3};
    numbers * NewNumbers;

    printf("struct a: %d\n", setNumber.a);
    printf("struct b: %d\n", setNumber.b);

    printf("After Function: \n");
    setNumbers(&setNumber);

    printf("struct a: %d\n", setNumber.a);
    printf("struct b: %d\n", setNumber.b);

    NewNumbers = setNumbers_2();

    NewNumbers->a = 20;
    NewNumbers->b = 30;

    printf("struct a: %d\n", NewNumbers->a);
    printf("struct b: %d\n", NewNumbers->b);

    free(NewNumbers);

    return (0);
}
void setNumbers(numbers * n) {
    n->a = 4;
    n->b = 5;
}
numbers * setNumbers_2() {
    numbers * new_number = (numbers *) malloc(sizeof(numbers));
    return new_number;
}