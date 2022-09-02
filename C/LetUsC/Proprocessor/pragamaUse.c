#include<stdio.h>

void func1();
void func2();

#pragma stratup func1
#pragma exit func2

int main() {
    printf("\nInside main");

    return(0);
}

void func1() {
    printf("\nInside func 1");
}
void func2() {
    printf("\nInside func 2");
}