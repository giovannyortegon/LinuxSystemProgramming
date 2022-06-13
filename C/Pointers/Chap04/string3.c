#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[]) {
    char * src = "Hello Pointer 3";
    char * dst = NULL;

    dst = (char *) malloc(sizeof(char) * (strlen(src) + 1));
    memcpy(dst, src, strlen(src));

    printf("%s\n", dst);
    
    return (0);
}