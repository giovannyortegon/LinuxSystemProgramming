#include<stdio.h>
#include<stdlib.h>

int main() {
    char env[50];

    printf("Enter the environment name: ");
    scanf("%s", env);

    printf("Enviroment value: %s\n", getenv(env));

    return(0);
}