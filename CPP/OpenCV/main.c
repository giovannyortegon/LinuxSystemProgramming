#include <stdio.h>
#include <cv.h>

int main(void)
{
	printf("%s\r\n", CV_VERSION);
	printf("%u.%u.%u\r\n",	CV_MAJOR_VERSION,
							CV_MINOR_VERSION,
							CV_SUBMINOR_VERSION);

	return (0);
}
