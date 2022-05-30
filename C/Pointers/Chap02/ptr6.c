#include<stdio.h>

int main() {
    int num = 10;
    int num2 = 30;
    int * const ptr = &num;

    printf("Value stored at pointer %d\n", *ptr);

    *ptr = 20;
    printf("Value stored at pointer %d\n", *ptr);

    // ptr = &num2;         // error 
    // printf("Value stored at pointer %d\n", *ptr);     // never print

    return (0);
}