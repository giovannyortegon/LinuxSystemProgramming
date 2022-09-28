#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>

int main() {
    struct dirent * dir_entry;
    int stat_dir;
    DIR * read_dir = opendir(".");

    if (read_dir == NULL) {
        fprintf(stderr, "Could not open current directory.\n");
        exit(1);
    }

    while ((dir_entry = readdir(read_dir)) != NULL ) {
        printf("%s\n", dir_entry->d_name);
    }

    stat_dir = closedir(read_dir);
    if (stat_dir == 0){
        fprintf(stdout, "Close success.\n");
    } else {
        fprintf(stderr, "Close success.\n");
    }

    return(0);
}