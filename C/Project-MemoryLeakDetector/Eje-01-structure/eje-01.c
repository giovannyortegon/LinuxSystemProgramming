#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct emp_ {
    char emp_name[30];
    unsigned int emp_id;
    unsigned int age;
    struct emp_ * mgr;
    float salary;
} emp_t;

int main(int argc, char * argv[]) {

    // emp_t *head;
    emp_t *emp01;
    // emp_t *emp02;

    emp01 = (emp_t *)malloc(sizeof(emp_t));
    strncpy(emp01->emp_name, "Dario", 6);
    emp01->emp_id = 1;
    emp01->age = 30;
    emp01->salary = 230.0;
    emp01->mgr = NULL;

    // emp02 = (emp_t *)malloc(sizeof(emp02));
    // strncpy(emp02->emp_name, "Diana", 6);
    // emp02->emp_id = 2;
    // emp02->age = 32;
    // emp02->salary = 230.0;
    // emp02->mgr = NULL;

    // head = emp01;

    // do {
    //     printf("Name: %s\n", head->emp_name);
    //     printf("Id: %u\n", head->emp_id);
    //     printf("Age: %u\n", head->age);
    //     printf("Salary: %f\n", head->salary);
    //     head = head->mgr;
    // }
    // while (head != NULL);

    printf("Name:\t\t%s\n", emp01->emp_name);
    printf("Name offset:\t%p\n", &emp01->emp_name);
    printf("Name size:\t%ld\n", sizeof(emp01->emp_name));
    printf("Id:\t\t%u\n", emp01->emp_id);
    printf("Id offset:\t%p\n", &emp01->emp_id);
    printf("Id size:\t%ld\n", sizeof(emp01->emp_id));
    printf("Age:\t\t%u\n", emp01->age);
    printf("Age offset:\t%p\n", &emp01->age);
    printf("Age size:\t%ld\n", sizeof(emp01->age));
    printf("Salary:\t\t%.2f\n", emp01->salary);
    printf("Salary offset:\t%p\n", &emp01->salary);
    printf("Salary size:\t%ld\n", sizeof(emp01->salary));
    
    // printf("Name: %s\n", emp02->emp_name);
    // printf("Name: %u\n", emp02->emp_id);
    // printf("Name: %u\n", emp02->age);
    // printf("Name: %f\n", emp02->salary);

    free(emp01);
    return (0);
}