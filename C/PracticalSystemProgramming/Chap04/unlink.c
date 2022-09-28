#include<stdio.h>
#include<unistd.h>

int main() {
    int unlink_status;
    char linkname[100];

    printf("Enter the link name to unlink: ");
    scanf("%[^\n]%*c", linkname);

    unlink_status = unlink(linkname);

    if (unlink_status == 0) {
        printf("File is unlinked successfully.!\n");
    } else {
        printf("Unable to unlink the file.!\n");
    }

    return (0);
}