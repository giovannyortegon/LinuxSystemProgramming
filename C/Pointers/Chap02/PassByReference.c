#include<stdio.h>

struct data {
    int x;
    int y;
};

void func(struct data * v1){
    struct data * v2 = v1;

    v2->x = 30;
    v2->y = 50;

    // printf("Value 1: %d\n", v2->x);
    // printf("Value 2: %d\n", v2->y); 
}

int main() {
    struct data var;

    var.x = 10;
    var.y = 20;

    printf("Value 1: %d\n", var.x);
    printf("Value 2: %d\n", var.y);

    func(&var);
    
    printf("Value 1: %d\n", var.x);
    printf("Value 2: %d\n", var.y);

    return (0);
}