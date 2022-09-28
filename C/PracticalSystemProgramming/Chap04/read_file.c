#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
    int file_descriptor, size;
    char filename[255];
    char * content = (char *)calloc(100, sizeof(char));

    printf("Enter the filename to read: ");
    scanf("%[^\n]%*c", filename);

    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1) {
        perror("File Not found.");
        exit(1);
    }
    size = read(file_descriptor, content, 100);
    printf("Number of bytes returned are: %d\n", size);
    content[99] = '\0';
    printf("File content: %s\n", content);
    
    close(file_descriptor);

    return (0);
}