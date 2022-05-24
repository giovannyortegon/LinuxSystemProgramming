/*
 * checkpass.c buffer overflow program
 */

#include<stdio.h>
#include<string.h>

int checkpass(void);

int main(void) {
    int r = checkpass();

    printf("checkpass: %d\n", r);

    return (0);
}

int checkpass(void) {
    int x;
    char a[9];

    x = 0;
    fprintf(stderr, "a at %p and\nx at %p\n", (void *)a, (void *)&x);
    printf("Enter a short word: ");
    scanf("%s", a);
    if (strcmp(a, "my pass") == 0)
        x = 1;

    return (x);
}