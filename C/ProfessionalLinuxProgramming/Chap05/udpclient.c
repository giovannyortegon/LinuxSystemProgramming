#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>


int main(int argc, const char * argv[]) {
    int s, fd, len, sin_size;
    struct sockaddr_in remote_addr;
    char buf[BUFSIZ];

    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote_addr.sin_port = htons(8000);

    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        perror("socket()");
        return (1);
    }

    strcpy(buf, "This is a test message.");
    printf("sending: %s\n", buf);
    sin_size = sizeof(remote_addr);
    len = sendto(s, buf, sizeof(buf), 0, (struct sockaddr *)&remote_addr, sin_size);
    if (len < 0) {
        perror("sendto()");
        return (1);
    }

    close(s);

    return(0);
}