#include<stdio.h>
#include<winsock2.h>

#pragma comment(lib, "win")

int main() {
	WSADATA d;
	
	if (WSAStartup(MAKEWORD(2, 2), &d)) {
		printf("Failed to initialized.\n");
		return (-1);
	}
	
	WSACleanup();
	printf("OK.\n");
	
	return (0);
}