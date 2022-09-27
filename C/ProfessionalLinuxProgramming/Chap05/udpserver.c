#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc, const char * argv[]) {
    int s, fd, len;
    struct sockaddr_in my_addr;
    struct sockaddr_in remote_addr;
    int sin_size;
    char buf[BUFSIZ];

    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(8000);
    my_addr.sin_addr.s_addr = INADDR_ANY;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        perror("socket()");
        return (1);
    }

    int sb = bind(s, (struct sockaddr *)&remote_addr, sizeof(remote_addr));
    if (sb < 0) {
        perror("bind()");
        return(1);
    }

    sin_size = sizeof(remote_addr);
    printf("waiting for a packet...\n");

    len = recvfrom(s, buf, BUFSIZ, 0, (struct sockaddr *)&remote_addr, &sin_size);
    if (len < 0) {
        perror("recvfrom()");
        return (1);
    }

    printf("received packet from: %s\n", inet_ntoa(remote_addr.sin_addr));
    buf[len] = '\0';
    printf("contents: %s\n", buf);

    close(s);

    return(0);
}