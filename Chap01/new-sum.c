#define _XOPEN_SOURCE 500
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void printhelp(char progname[]);

int main(int argc, char *argv[])
{
    int i, opt, sum;

    /* simple sanity chack */
    if (argc == 1)
    {
        printhelp(argv[0]);
        return (1);
    }

    while ((opt = getopt(argc, argv, "smh")) != -1)
    {
        switch (opt)
        {
            case 's': /* sum the integers */
                sum = 0;

                for (i = 2; i < argc; i++)
                    sum += atoi(argv[i]);
       //         break;
                continue;

            case 'm': /* multiply the integers */
                sum = 1;

                for (i = 2; i < argc; i++)
                    sum *= atoi(argv[i]);
     //           break;
                continue;

            case 'h': /* -h for help */
                printhelp(argv[0]);
                return (0);

            default:  /* in case of  invalid option */
                printhelp(argv[0]);
                return (0);
        }
    }

    printf("Total: %i\n", sum);
    return (0);
}
void printhelp(char progname[])
{
    printf("%s [-s] [-m] integer ...\n", progname);
    printf("-s sums all the integers\n"
            "-m multiplies all the integers\n"
            "This program takes any number of integer "
            "values and either add or multiply them.\n"
            "For example: %s -m 5 5 5\n", progname);
}
