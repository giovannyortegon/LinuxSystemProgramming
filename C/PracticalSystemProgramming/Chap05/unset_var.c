#include<stdio.h>
#include<stdlib.h>

int main() {
    char var_name[50];

    printf("Enter the variable to Delete: ");
    scanf("%s", var_name);

    int status = unsetenv(var_name);

    if (status == 0)
        printf("Environment variable is Deleted Successfully.\n");
    else
        printf("Unable to Delete the environemnt variable.\n");

    return (0);
}