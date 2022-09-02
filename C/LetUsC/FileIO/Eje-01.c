#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE * fp;
    char ch;
    int counter = 0;
    int ntb = 0, nsp = 0, nnl = 0;

    fp = fopen("Poem.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "can not open file.\n");
        exit(-1);
    }

    while (1) {
        ch = fgetc(fp);
        counter++;
        if (ch == EOF) {
            break;
        }
        if (ch == '\n')
            nnl++;

        if (ch == '\r')
            ntb++;

        if (ch == ' ')
            nsp++;

        printf("%c", ch);
    }
    printf("\nNumber charanters: %d\n", counter);
    printf("\nNumber new lines: %d\n", nnl);
    printf("\nNumber tabs: %d\n", ntb);
    printf("\nNumber spaces: %d\n", nsp);
    fclose(fp);
}