#include<stdio.h>
#include<unistd.h>

int main() {
    int link_status;
    char filepath[50], linkname[50];

    printf("Enter the filename: ");
    scanf("%[^\n]%*c", filepath);

    printf("Enter the linkname: ");
    scanf("%[^\n]%*c", linkname);

    link_status = link(filepath, linkname);

    if ( link_status == 0) {
        printf("Hardlink is created successfully.\n");
    } else {
        printf("Unable to create the hard link.\n");
    }

    return (0);
}