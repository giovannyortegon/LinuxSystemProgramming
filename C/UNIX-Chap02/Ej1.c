#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char * argv[]){
    char delimit[] = " \t";
    char * s = "hola a todos";
    const char * snew;
    
    printf("%ld\n", strlen(argv[1]));

    snew = argv[1] + strspn(argv[1], delimit);

    printf("%s\n", snew);
    printf("%ld\n", strlen(snew));

    return (0);
}