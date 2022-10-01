#include<stdio.h>

int main() {
    FILE * fp = NULL;
    int res, data;

    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("File opening error.\n");
    } else {
        printf("File opening success.\n");
    }

    while ((data = fgetc(fp)) != EOF) {
        if(data != 10)
            printf("%d %c ", data, (char)data);
        else
            printf("\n");
    }
    

    res = fclose(fp);

    if (res == 0) {
        printf("File closed.\n");
    } else {
        printf("Unable to close file.\n");
    }

    return (0);
}