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
    struct sockaddr_un name;

/*
   struct sockaddr_un {
        sa_family_t sun_family;         // AF_UNIX
        char sun_path[108];             // pathname
   }
*/

    int ret;
    int connection_socket;
    int data_socket;
    int result;
    int data;
    char buffer[BUFFER_SIZE];

    // If program exit before remove the socket
    // unlink(SOCKET_NAME);

    // create socket
    connection_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (connection_socket == -1) {
        perror("Soket");
        exit(EXIT_FAILURE);
    }

    printf("Master socket created.\n");

    // initialize structure
    memset(&name, 0, sizeof(struct sockaddr_un));

    // specify credential socket
    name.sun_family = AF_UNIX;
    strncpy(name.sun_path, SOCKET_NAME, sizeof(name.sun_path)-1);

    // attach socket
    ret = bind(connection_socket, (const struct sockaddr *)&name, sizeof(struct sockaddr_un));
    if (ret == -1) {
        perror("Bind");
        exit(EXIT_FAILURE);
    }

    printf("bind() call succeed.\n");
    ret = listen(connection_socket, 20);
    if (ret == -1) {
        perror("Listen");
        exit(EXIT_FAILURE);
    }

    // loop for handling connections
    for(;;) {
        printf("Waiting on accept() syscall.\n");

        data_socket = accept(connection_socket, NULL, NULL);
        if (data_socket == -1) {
            perror("Acept");
            exit(EXIT_FAILURE);
        }

        printf("Connection accpeted from client.\n");

        result = 0;

        // Get data and realize operations
        for(;;) {
            memset(buffer, 0, BUFFER_SIZE);
            printf("Waiting for data from client:\n");
            ret = read(data_socket, buffer, BUFFER_SIZE);
            if (ret == -1) {
                perror("Read");
                exit(EXIT_FAILURE);
            }

            // Receive and realize operation
            memcpy(&data, buffer, sizeof(int));
            if (data == 0) break;
            result += data;
        } // for: Get data and realize operations

        memset(buffer, 0, BUFFER_SIZE);
        sprintf(buffer, "Result = %d\n", result);

        printf("sending final result back to client.\n");

        // Send result to client
        ret = write(data_socket, buffer, BUFFER_SIZE);
        if (ret == -1) {
            perror("Write");
            exit(EXIT_FAILURE);
        }
        // close socket
        close(data_socket);
    } // for: Handle connections

    close(connection_socket);
    printf("connection closed.\n");

    // realise server resource
    unlink(SOCKET_NAME);
    exit(EXIT_FAILURE);
}