/*
 * Professonal Linux Programming - Simple TCP client 
 */

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc, const char * argv[]) {
    int s, con, len;
    struct sockaddr_in remote_addr;
    char buf[BUFSIZ];

    memset(&remote_addr, 0, sizeof(remote_addr));

    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote_addr.sin_port = htons(8000);

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        perror("socket()");
        return(-1);
    }

    con = connect(s, (struct sockaddr *)&remote_addr, sizeof(remote_addr));
    if (con < 0) {
        perror("connect()");
        return (-1);
    }

    printf("connected to server\n");
    len = recv(s, buf, BUFSIZ, 0);
    buf[len] = '\0';
    printf("client: %s\n", buf);

    while (1) {
        printf("Enter string to send: ");
        scanf("%s", buf);
        if (!strcmp(buf, "quit")) {
            break;
        }
        len = send(s, buf, strlen(buf), 0);
        len = recv(s, buf, BUFSIZ, 0);
        buf[len] = '\0';
        printf(" received: %s\n", buf);
    }

    close(s);

    return (0);
}