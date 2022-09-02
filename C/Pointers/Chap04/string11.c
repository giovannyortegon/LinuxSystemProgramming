#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void freestring(char arr[], int length);

int main(int argc, char * argv[]) {
    char * arr[6];
    char tempstring[30];
    int i, lenstr;

    for (i = 0; i < 6; i++) {
        printf("Insert data\n");
        scanf("%s", tempstring);
        lenstr = strlen(tempstring) + 1;
        arr[i] = (char *) malloc (sizeof(char)* lenstr);
        strncpy(arr[i], tempstring, lenstr);
    }

    printf("Data in array\n");
    for (i = 0; i < 6; i++) {
        printf(" %d - %s\n", i, arr[i]);
    }

    freestring(arr, 5);

    return (0);
}
void freestring(char arr[], int length) {
    int i;

    for (i = 0; i < length; i++) {
        free(arr[i]);
    }
}