#include<stdio.h>

int main() {
    int num = 20;
    int num2 = 500;
    const int * ptr;

    ptr = &num;
    // *ptr = 30;       // error, I cant change the value from ptr
    ptr = &num2;        // I cant change where to point ptr
    printf("Value * ptr: %d\n", *ptr);

    return (0);
}