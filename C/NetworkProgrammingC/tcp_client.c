#include"chap03.h"

#if defined(_WIN32)

#include<conio.h>

#endif

int main(int argc, char * argv[]) {

#if defined(_WIN32)
    WSADATA d;

    if (WSAStartup(MAKEUP(2, 2), &d)) {
        fprintf(stderr, "Failed to initialize.\n");

        return (1);
    }
#endif

    if (argc < 3) {
        fprintf(stderr, "usage: tcp_client <hostname:port>\n");
        return (1);
    }

    printf("Configuring  remote address...\n");
    struct addrinfo hints;

    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo *peer_address;

    if (getaddrinfo(argv[1], argv[2], &hints, &peer_address)) {
        fprintf(stderr, "getaddrinfo() failed. (%d)\n", GETSOCKETERRNO());
        return (1);
    }
}