#include<stdio.h>

char * foo(void);

int main(int argc, char * argv[]) {

    char * m = foo();        // Error 

    printf("Printing local value of function foo = %s\n", m);      // no compile

    return (0);
}
char * foo(void) {
    char * str = "STRING";

    return str;
}