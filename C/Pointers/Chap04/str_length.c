#include<stdio.h>

int str_length(char * src);

int main(int argc, char * argv[]) {

    char strliteral[] = "ADD";

    int len = str_length(strliteral);

    printf("%s\n", strliteral);
    printf("%d\n", len);
    
    return (0);
}
int str_length(char * src) {
    int str_len = 0;
    char * ptr = NULL;
    ptr = src;

    while (*ptr != '\0') {
        str_len++;
        // printf("%d\n", str_len);
        ptr++;
    }

    return (str_len);   
}