#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

#define MAXSIZE 4096

int main(int argc, char * argv[])
{
	int fd;					/* for the file descriptor */
	int maxread;			/* the maximum we want to read */
	off_t filesize;			/* for the file size */
	struct stat fileinfo;	/* struct for fstat */
	char rbuf[MAXSIZE];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <path>\n", argv[0]);
		return (1);
	}

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror("Can't open file for reading");
		return (1);
	}

	fstat(fd, &fileinfo);
	filesize = fileinfo.st_size;

	/* determine the max size we want toread so we don't overflow
	   the read buffer */
	if (filesize >= MAXSIZE)
		maxread = MAXSIZE -1;
	else
		maxread = filesize;

	/* read the content and print it */
	if ((read(fd, rbuf, maxread)) == -1)
	{
		perror("Can't read file");
		return (1);
	}

	close(fd);
	printf("%s", rbuf);
	return (0);
}
