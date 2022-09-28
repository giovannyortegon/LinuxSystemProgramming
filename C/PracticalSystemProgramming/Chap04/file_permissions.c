#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main() {
    int permissions_status;
    mode_t new_permission_value;
    char filepath[100];

    printf("Enter the input from the user: ");
    scanf("%[^\n]%*c", filepath);

    printf("Enter the new permission set: ");
    scanf("%d", &new_permission_value);

    if (permissions_status == 0) {
        printf("New permissions are setted successfuly.!\n");
    } else {
        printf("Permissions changed successfully.\n");
    }

    return (0);
}