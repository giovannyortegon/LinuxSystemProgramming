#include<stdio.h>

int main() {
    struct header {
        int version;
        int signature;
        struct tagme {
            int id;
            int offset;
        }tagid;
    };

    struct header hdrinfo;
    hdrinfo.version = 0;
    hdrinfo.signature = 5;
    hdrinfo.tagid.id = 1;
    hdrinfo.tagid.offset = 10;

    printf("%d\n", hdrinfo.version);
    printf("%d\n", hdrinfo.signature);
    printf("%d\n", hdrinfo.tagid.id);
    printf("%d\n", hdrinfo.tagid.offset);

    return (0);
}