/* A correct use of strtok_r to determine the average number of words per line */
#include<string.h>

#define LINE_DELIMITERS "\n"
#define WORD_DELIMITERS " "

static int wordcount(char *s) {
    int count = 1;
    char * lasts;

    if (strtok_r(s, WORD_DELIMITERS, &lasts) == NULL)
        return (0);

    while (strtok_r(NULL, WORD_DELIMITERS, &lasts) != NULL) {
        count++;
    }
    
    return (count);
}

double wordaverage(char *s) {
    char * lasts;
    int linecount = 1;
    char * nextline;
    int words;

    nextline = strtok_r(s, LINE_DELIMITERS, &lasts);
    if (nextline == NULL)
        return (0.0);

    words = wordcount(nextline);

    while ((nextline = strtok_r(NULL, LINE_DELIMITERS, &last)) != NULL) {
        words += wordcount(nextline);
        linecount++;
    }

    return ((double) words/linecount);
}