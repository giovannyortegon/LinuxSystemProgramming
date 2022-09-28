#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main() {
    int isRemoved;
    char DIR_NAME[512];

    printf("Enter the directory name you want to create: ");
    scanf("%[^\n]%*c", DIR_NAME);

    isRemoved = rmdir(DIR_NAME);

    if (isRemoved == 0) {
        printf("Directory is deleted successfully.\n");
    } else {
        printf("Unable to delete directory.\n");
    }

    return (0);
}