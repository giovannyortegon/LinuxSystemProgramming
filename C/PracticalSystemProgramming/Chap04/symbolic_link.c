#include<stdio.h>
#include<unistd.h>

int main() {
    int link_status;
    char filepath[50], linkname[50];

    printf("Enter the filepath: ");
    scanf("%[^\n]%*c", filepath);
    printf("Enter the linkname: ");
    scanf("%[^\n]%*c", linkname);

    if (link_status == 0) {
        printf("Soft link is Created successfully.!\n");
    } else {
        printf("Unable to create the link.\n");
    }

    return (0);
}