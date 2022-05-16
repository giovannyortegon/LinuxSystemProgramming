#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char * c;

    c = calloc(sizeof(char), 20);

    strcpy(c, "Hello!, how are you?");

    printf("%s\n", c);

    free(c);

    return (0);
}