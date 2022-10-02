#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *fp;
    int res;
    int index;
    char * datafromfile = (char *)malloc(sizeof(char)*6);

    fp = fopen("test-2.txt", "w");
    if (fp == NULL) {
        printf("File opening error.\n");
        return (-1);
    } else 
        printf("File opening success.\n");


    fputs("Hello NAV.", fp);
    fclose(fp);
    fp = fopen("test-2.txt", "r");

    // read the current content
    fgets(datafromfile, 6, fp);
    printf("Current content of file %s\n", datafromfile);
    rewind(fp);         // restting the file pointer
    fseek(fp, 6, SEEK_SET);     // seeks file pointer to offset values 6 from beginning of file.
    memset(datafromfile, 0, sizeof(char));
    fgets(datafromfile, 6, fp);
    printf("Content of data %s\n", datafromfile);
    fseek(fp, 0L, SEEK_SET);    // seeks file pointer to offset value 0 from beginning of file
    memset(datafromfile, 0, sizeof(char));
    fgets(datafromfile, 6, fp);
    printf("Content of data %s\n", datafromfile);

    res = fclose(fp);
    if (res == 0)
        printf("File closed.\n");
    else {
        printf("Unable to close file.\n");
    }

    return (0);
}