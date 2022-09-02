#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE * fp;
    char s[80];

    fp = fopen("Poem.txt", "r");
    if (fp == NULL){
        fprintf(stderr, "can not open sourse file.\n");
        exit(-1);
    }

    while (fgets(s, 79, fp) != NULL) {
        printf("%s", s);
    }

    fclose(fp);
}