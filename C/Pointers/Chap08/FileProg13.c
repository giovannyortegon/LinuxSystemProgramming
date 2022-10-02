#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *fp;
    int res;
    int val = 0;
    char * data = (char*)malloc(sizeof(char)*11);

    fp = fopen("test-2.txt", "r");
    if (fp == NULL) {
        printf("File opening error.\n");
        return (-1);
    } else 
        printf("File opening success.\n");

    if(fgets(data, 11, fp))
        printf("%s\n", data);
    else
        printf("Line reading failure\n");

    rewind(fp);

    while((val = fgetc(fp)) != EOF) {
        if (val != 10)
            printf("%c", (char)val);
        else
            printf("\n");
    }

    res = fclose(fp);
    if (res == 0)
        printf("\nFile closed.\n");
    else {
        printf("\nUnable to close file.\n");
    }

    return (0);
}