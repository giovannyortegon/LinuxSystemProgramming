#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<unistd.h>

#define SOCKET_NAME "/tmp/DemoSocket"
#define BUFFER_SIZE 128

int main(int argc, char * argv[]) {
    struct sockaddr_un addr;
    int i;
    int ret;
    int data_socket;
    char buffer[BUFFER_SIZE];

    // create data socket
    data_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (data_socket == -1) {
        perror("Socket");
        exit(EXIT_FAILURE);
    }

    // inicialize structure
    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_NAME, sizeof(addr.sun_path)-1);

    // connect
    ret = connect(data_socket, (const struct sockaddr *)&addr,
                sizeof(struct sockaddr_un));
    if (ret == -1) {
        fprintf(stderr, "The server is down.\n");
        exit(EXIT_FAILURE);
    }

    do {
        printf("Enter number to send to server: ");
        scanf("%d", &i);
        ret = write(data_socket, &i, sizeof(int));
        if (ret == -1) {
            perror("Write");
            break;
        }
        printf("No of bytes sent: %d, data sent: %d\n", ret, i);
    } while (i);

    // request result
    memset(buffer, 0, BUFFER_SIZE);
    strncpy(buffer, "RES", strlen("RES"));
    buffer[strlen(buffer)] = '\0';
    printf("buffer: %s\n", buffer);

    ret = write(data_socket, buffer, strlen(buffer));
    if (ret == -1) {
        perror("Write");
        exit(EXIT_FAILURE);
    }
       
    // receive result
    memset(buffer, 0, BUFFER_SIZE);
    ret = read(data_socket, buffer, BUFFER_SIZE);
    if (ret == -1) {
        perror("Read");
        exit(EXIT_FAILURE);
    }

    // ensure buffer is 0 terminated
    buffer[BUFFER_SIZE-1] = '\0';
    printf("Result: %s\n", buffer);

    close(data_socket);
    exit(EXIT_FAILURE);

}