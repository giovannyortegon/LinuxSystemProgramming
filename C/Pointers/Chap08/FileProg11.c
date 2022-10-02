#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *fp;
    int res;
    int fileoffset = 0;

    fp = fopen("test-2.txt", "w");
    if (fp == NULL) {
        printf("File opening error.\n");
        return (-1);
    } else 
        printf("File opening success.\n");


    fputs("Hello NAV.", fp);
    fclose(fp);
    fp = fopen("test-2.txt", "r");
    fileoffset = ftell(fp);
    printf("File offset at default position %d\n", fileoffset);
    fseek(fp, 0, SEEK_END);
    fileoffset = ftell(fp);
    printf("File offset after seeking %d\n", fileoffset);

    res = fclose(fp);
    if (res == 0)
        printf("File closed.\n");
    else {
        printf("Unable to close file.\n");
    }

    return (0);
}