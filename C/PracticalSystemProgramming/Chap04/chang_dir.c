#include<stdio.h>
#include<unistd.h>

int main() {
    char DIR[BUFSIZ];
    printf("Working directory before operation: %s\n", getcwd(DIR, BUFSIZ));

    int status = chdir("..");
    if (status == 0) {
        printf("Directory changed to %s\n", getcwd(DIR, BUFSIZ));
    } else {
        printf("Unable to change the directory.\n");
    }

    return (0);

}