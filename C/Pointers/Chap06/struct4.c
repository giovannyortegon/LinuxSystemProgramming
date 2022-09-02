#include<stdio.h>

int main() {
    struct data {
        int i;
        int j;
        int k;
    };

    struct data v1;
    printf("Size of structure data: %ld\n", sizeof(struct data));

    return (0);
}