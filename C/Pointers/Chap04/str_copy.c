#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int str_copy(char * dst, const char * src);

int main(int argc, char * argv[]) {

    char strliteral[] = "ADD";
    char * arr;
    int len = 0;

    arr = (char *) malloc(sizeof(char) * strlen(strliteral) + 1);


    len = str_copy(arr, strliteral);

    printf("%s\n", arr);
    printf("%d\n", len);

    free(arr);
 
    return (0);
}
int str_copy(char * dst, const char * src) {
    int str_len = 0;
    const char * ptr_src = src;
    char * ptr_dst = dst;

    while (*ptr_src != '\0') {
        str_len++;
        ptr_src++;
    }

     while (*src != '\0') {
        * ptr_dst = * src;
        src++;
        ptr_dst++;
    }
    * ptr_dst = '\0';

    return str_len;
}