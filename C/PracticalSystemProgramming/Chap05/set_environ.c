#include<stdio.h>
#include<stdlib.h>

int main() {
    char var_name[15];
    char var_value[15];
    int overwrittenValue;

    printf("Enter your variable name: ");
    scanf("%s", var_name);
    printf("Enter the variable Value: ");
    scanf("%s", var_value);

    // 1 --> Represents the overwrite of value.
    // 0 --> Doesn't overwrite value
    printf("Enter tne overriden Value: ");
    scanf("%d", &overwrittenValue);

    int status = setenv(var_name, var_value, overwrittenValue);

    if (status == 0)
        printf("Enviroment variable Created successfully.\n");
    else if (status == -1)
        printf("Environment variable Created Unsuccessfully.\n");

    return (0);
}