#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *fp;
    int res;
    int index;
    int numofdatatowrite;
    char * namefmt = "fwrite - First Middle Last.";

    fp = fopen("test-2.txt", "w");
    if (fp == NULL) {
        printf("File opening error.\n");
        return (-1);
    } else 
        printf("File opening success.\n");


    numofdatatowrite = 5;
    if (numofdatatowrite == fwrite(namefmt, sizeof(char), numofdatatowrite, fp))
        printf("Success in writting data.\n");
    else 
        printf("Unsuccess in writting data.\n");

    res = fclose(fp);
    if (res == 0)
        printf("File closed.\n");
    else {
        printf("Unable to close file.\n");
    }

    return (0);
}