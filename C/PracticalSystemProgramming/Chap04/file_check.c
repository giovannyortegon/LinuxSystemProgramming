#include<stdio.h>
#include<unistd.h>

int main() {
    char filepath[100];

    printf("Enter the filename with path: ");
    scanf("%[^\n]%*c", filepath);

    int read_status, file_status, write_status;
    file_status = access(filepath, F_OK);

    if(file_status == -1) {
        printf("%s File does not exist in Location.\n", filepath);
        _exit(0);
    }

    read_status = access(filepath, R_OK);
    write_status = access(filepath, W_OK);

    if (read_status == 0 && write_status == 0) {
        printf("%s File has both read and write permissions\n", filepath);
    } else if (read_status == 0 && write_status == -1){
        printf("%s File has only read permissions\n", filepath);
    } else if (read_status == -1 && write_status == 0) {
        printf("%s File has only write permissions.\n", filepath);
    } else {
        printf("%s File has no read and write permissions.\n", filepath);
    }

    return (0);
}