#include<stdio.h>

int main() {
    int data[5][5];
    int i, j;
    int count = 0;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            data[i][j] = count++;
        }
    }

    printf("Start address of the array %p\n", data);
    for (i = 0; i < 5; i++) {
        printf(" %dth row = %p\n", i, data[i]);
        printf("Columns\n");
        for (j = 0; j < 5; j++)
            printf("%d = %p, ", j, data[i]+j);
        printf("\n");
    }

    return (0);
}