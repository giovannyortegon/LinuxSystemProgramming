#include<stdio.h>

void printHelp(FILE * stream, char progname[])
{
	fprintf(stream, "\nUsage: %s [-c] [-t] [-r] [-h]\n"
	"-c calculate the area of a circle\n"
	"-t calculate the area of a triangle\n"
	"-r calculate the area of a rectangle\n"
	"-h shows this help\n"
	"Example the height and wodth of the triangle: 5 9\n"
	"22.500\n", progname, progname
	);
}
