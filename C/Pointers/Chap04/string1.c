#include<string.h>
#include<stdio.h>

int main(int argc, char * argv[]) {
    char * str = "Hello Pointer";
    int i = 0;

    for (i = 0; i < strlen(str); i++) {
        printf("%c ", str[i]);
    }

    printf("\n");

    return (0);
}