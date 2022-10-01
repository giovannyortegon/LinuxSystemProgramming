#include<stdio.h>
#include<stdlib.h>

#define BUFFER 4


int main(int argc, char * argv[]) {
    FILE * fp = NULL;
    int res;
    char * src = NULL;
    unsigned char chr;
    int fpos;

    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("File opening error.\n");
    } else {
        printf("File opening success.\n");
    }

    src = (char *) malloc(sizeof(char) * BUFFER);
    fpos = ftell(fp);
    printf("File pointer pos before reading = %d\n", fpos);

    if(fgets(src, BUFFER, fp))
        printf("%s \n", src);
    else
        printf("Line reading failure.\n");

    fpos = ftell(fp);
    printf("File pointer pos after reading = %d\n", fpos);
    
    res = fclose(fp);
    if (res == 0) {
        printf("File closed.\n");
    } else {
        printf("Unable to close file.\n");
    }

    return (0);
}