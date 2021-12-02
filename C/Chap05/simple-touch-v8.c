#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<utime.h>

#define MAX_LENGTH 100

int main(int argc, char * argv[])
{
	char filename[MAX_LENGTH] = {0};

	/* check number of arguments */
	if (argc != 2)
	{
		fprintf(stderr, "You must supply a filename as an argument\n");
		return (1);
	}

	strncat(filename, argv[1], sizeof(filename) - 1);

	/* update the acces and modification time */
	if (utime(filename, NULL) == -1)
	{
		/* if the file doesn't exist, create it */
		if (errno == ENOENT)
		{
			if (creat(filename, 00644) == -1)
			{
				perror("Can't create file");
				return (errno);
			}
		}
		else
		{
			perror("Can't update timestamp");
			return (errno);
		}
	}

	return(0);
}
