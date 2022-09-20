/*
 * Professional linux programming - simple TCP server.
 */
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main() {
    int s, fd, len, b;
    struct sockaddr_in my_addr;
    struct sockaddr_in remote_addr;
    int sin_size;

    char buffer[BUFSIZ];

    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = INADDR_ANY;
    my_addr.sin_port = htons(8000);
    
    s = socket(AF_INET, SOCK_STREAM, 0);

    if (s < 0) {
        perror("socket");
        return (1);
    }

    b = bind(s, (struct sockaddr *)&my_addr, sizeof(struct sockaddr));
    if (b < 0) {
        perror("bind");
        return (1);
    };

    listen(s, 5);
    sin_size = sizeof(struct sockaddr_in);
        
    fd = accept(s, (struct sockaddr *)&remote_addr, &sin_size);
    if (fd < 0) {
        perror("accept");
        return (1);
    }

    printf("accept client %s\n", inet_ntoa(remote_addr.sin_addr));
    len = send(fd, "Welcome to my server\n", 21, 0);

    while ((len = recv(fd, buffer, BUFSIZ, 0)) > 0) {
        buffer[len] = '\0';
        printf("%s\n", buffer);
        if (send(fd, buffer, len, 0) < 0) {
            perror("write");
            return (1);
        }
    }

    close(fd);
    close(s);

    return (0);
}
