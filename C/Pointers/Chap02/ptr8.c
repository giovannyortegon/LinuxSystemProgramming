#include<stdio.h>

int main() {
    int num = 20;
    int num2 = 500;
    const int * const ptr = &num;

    printf("Value * ptr: %d\n", *ptr);
    // *ptr = 30;       // error, I cant change the value from ptr
    //ptr = &num2;        // error, I cant change the addres location

    num = 30;
    printf("Value * ptr: %d\n", *ptr);

    return (0);
}