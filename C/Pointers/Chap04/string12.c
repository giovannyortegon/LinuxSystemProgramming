#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void freestrmemory(char** arr, int length);

int main(int argc, char * argv[]) {
    char **arr = NULL;
    char temstring[30];
    int i, lenstr;

    for (i = 0; i < 6; i++) {
        printf("Insert data\n");
        scanf("%s", temstring);
        lenstr = strlen(temstring) + 1;

        if (arr == NULL) {
            arr = (char**)malloc(sizeof(char*));
        } else {
            arr = (char**)realloc(arr, sizeof(char*)*i+1);
        }

        arr[i] = (char *) malloc(sizeof(char)*lenstr);
        strncpy(arr[i], temstring, lenstr);
    }

    for (i = 0; i < 6; i++) {
        printf(" %d - %s\n", i, arr[i]);
    }

    freestrmemory(arr, 5);

    return (0);
}

void freestrmemory(char** arr, int length) {
    int i;
    for( i = 0; i<=length; i++) {
        free(arr[i]);
    }
    free(arr);
}