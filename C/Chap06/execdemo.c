#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
                
int main(int argc, char * argv[])
{
	printf("My PID is %d\n", getpid());
	printf("Hit enter to continue ");

	printf("Executing /usr/bin/less...\n");

	/* execute less using execl and error check it */
	if (execl("/usr/bin/more", argv[0],
              "/etc/passwd", (char *)NULL) == -1)
	{
		perror("Can't execute program");
		return (1);
	}

	return (0);
}
