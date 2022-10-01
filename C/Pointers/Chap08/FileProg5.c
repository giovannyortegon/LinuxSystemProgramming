#include<stdio.h>
#include<stdlib.h>

#define BUFFER 20

int main() {
    FILE * fp = NULL;
    int res;
    char * str = NULL;

    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("File opening error.\n");
    } else {
        printf("File opening success.\n");
    }

    str = (char *)malloc(BUFFER * sizeof(char));
    res = fread(str, sizeof(char), BUFFER-1, fp);
    str[4] = '\0';

    if (res)
        printf("%s\n", str);
    else
        printf("Line reading failure.\n");

    res = fclose(fp);

    if (res == 0) {
        printf("File closed.\n");
    } else {
        printf("Unable to close file.\n");
    }

    return (0);
}