#include<string.h>
#include<stdio.h>

int main(int argc, char * argv[]) {
    char * str = "Hello Pointer 2";
    char * ptr = str;

    while (*ptr != '\0') {
        printf("%c ", *ptr);
        ptr++;
    }
    
    printf("\n");

    return (0);
}