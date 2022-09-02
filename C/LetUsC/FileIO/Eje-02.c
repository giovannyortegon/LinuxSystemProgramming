#include<stdio.h>
#include <stdlib.h>

int main() {
    FILE * fs, *ft;
    char ch;

    fs = fopen("pragmaUse.c", "r");
    if (fs == NULL) {
        fprintf(stderr, "can not open sourse file.\n");
        exit(-1);
    }

    ft = fopen("copyPragmaUse.c", "w");
    if (ft == NULL) {
        fprintf(stderr, "can not open sourse file.\n");
        exit(-2);
    }

    while(1) {
        ch = fgetc(fs);
        if (ch == EOF)
            break;
        else
            fputc(ch, ft);
    }
    fclose(fs);
    fclose(ft);
}