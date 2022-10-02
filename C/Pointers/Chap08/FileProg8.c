#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *fp;
    int res;
    int index;
    char * namefmt = "First Middle Last.";

    fp = fopen("test-2.txt", "w");
    if (fp == NULL) {
        printf("File opening error.\n");
        return (-1);
    } else 
        printf("File opening success.\n");

    fputs(namefmt, fp);

    res = fclose(fp);
    if (res == 0)
        printf("File closed.\n");
    else {
        printf("Unable to close file.\n");
    }

    return (0);
}