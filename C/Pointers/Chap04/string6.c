#include<stdio.h>

int main(int argc, char * argv[]) {

    char * strliteral = "ADD";
    strliteral[0] = 'B';

    printf("%s\n", strliteral);
    
    // printf("%s\n", strliteral);

    return (0);
}