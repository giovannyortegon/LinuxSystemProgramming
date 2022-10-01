#include<stdio.h>
#include<stdlib.h>

#define BUFFER 5

int main() {
    FILE * fp = NULL;
    int res;
    int index;
    char * name = NULL;
    char * country = NULL;

    fp = fopen("test-1.txt", "r");
    if (fp == NULL) {
        printf("File opening error.\n");
    } else {
        printf("File opening success.\n");
    }

    name = (char *)malloc(BUFFER * sizeof(char));
    country = (char *)malloc(BUFFER * sizeof(char));

    while (!feof(fp)) {
        fscanf(fp, "%d %s %s", &index, name, country);
        printf("%d %s %s\n", index, name, country);
    }

    res = fclose(fp);

    if (res == 0) {
        printf("File closed.\n");
    } else {
        printf("Unable to close file.\n");
    }

    return (0);
}