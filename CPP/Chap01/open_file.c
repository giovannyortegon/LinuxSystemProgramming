#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
	int fileDes = open("myFile.txt", O_RDONLY);

	if (fileDes == -1)
	{
		fprintf(stderr, "Can not open myFile.txt... errno: %d\n", fileDes);
		fprintf(stderr, "errno code = %d\n", errno);
		fprintf(stderr, "errno meaning = %s\n", strerror(errno));
		exit(1);
	}
	return (0);
}
