#include<stdio.h>
#include<fcntl.h>

int main() {
    int file_descriptor;
    char filename[255];

    printf("Enter the filename: ");
    scanf("%s", filename);

    // setting permission to read and write
    file_descriptor = creat(filename, O_RDWR|O_CREAT);
    if (file_descriptor != -1) {
        printf("File created successfully!\n");
    } else {
        printf("Unable to create the File.\n");
    }

    // close file
    int close_status = close(file_descriptor);
    if (close_status == 0) {
        printf("File descriptor is closed Successfully.\n");
    } else {
        printf("File descriptor is not closed\n");
    }

    return (0);
}