#include<stdio.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define STORAGE_ID1 "/SHM_USER1"
#define STORAGE_ID2 "/SHM_USER2"
#define STORAGE_SIZE 32

int main(int argc, char * argv[]) {
    char message1[STORAGE_SIZE];
    char message2[STORAGE_SIZE];
    int fd1 = shm_open(STORAGE_ID1, O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
    int fd2 = shm_open(STORAGE_ID2, O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);

    if ((fd1 == -1) || (fd2 == -1)) {
        perror("open");
        return (10);
    }

    int res1 = ftruncate(fd1, STORAGE_SIZE);
    if (res1 == -1) {
        perror("ftruncate");
        return (20);
    }

    void * addr1 = mmap(NULL, STORAGE_SIZE, PROT_WRITE, MAP_SHARED, fd1, 0);
    void * addr2 = mmap(NULL, STORAGE_SIZE, PROT_WRITE, MAP_SHARED, fd2, 0);

    if ((addr1 == MAP_FAILED) || (addr2 == MAP_FAILED)) {
        perror("mmap");
        return (30);
    }

    while (1) {
        printf("USER 1: ");
        fgets(message1, STORAGE_SIZE, stdin);
        int len = strlen(message1) + 1;
        memcpy(addr1, message1, len);
        printf("USER 2 (enter to get the message): ");
        getchar();
        memcpy(message2, addr2, STORAGE_SIZE);
        printf("%s\n", message2);
    }

    return (0);    
}
