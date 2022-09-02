#include<stdio.h>

struct data {
    int x;
    int y;
};

void func(struct data v1){
    struct data v2 = v1;

    printf("Value 1: %d\n", v2.x);
    printf("Value 2: %d\n", v2.y); 
}

int main() {
    struct data var;

    var.x = 10;
    var.y = 20;

    func(var);

    return (0);
}