#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>

int main() {
    int isCreated;
    char * DIR_NAME;

    printf("Enter the directory name you want to create: ");
    scanf("%[^\n]%*c", DIR_NAME);

    isCreated = mkdir(DIR_NAME, 0777);

    if (isCreated == 0) {
        printf("Directory is created successfully.\n");
    } else {
        printf("Unable to create directory.\n");
    }

    return (0);
}