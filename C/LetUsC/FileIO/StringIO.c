#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char s[80];

    fp = fopen("Poem.txt", "w");
    if (fp == NULL){
        fprintf(stderr, "can not open sourse file.\n");
        exit(-1);
    }

    printf("\nEnter a few lines of text:\n");
    gets(s);
    while (strlen(s) > 1){
        fputs(s, fp);
        fputs("\n", fp);
        gets(s);
    }
    fclose(fp);   
}