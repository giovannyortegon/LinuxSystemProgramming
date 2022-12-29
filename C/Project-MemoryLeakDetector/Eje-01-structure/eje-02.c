#include<stdio.h>
#include<string.h>

typedef struct _student {
    char stud_name[32];
    int rollho;
    int age;
} student_t;

int main(int argc, char * argv[]) {
    student_t array_students[3];

    strncpy(array_students[0].stud_name, "Manuel", 5);
    array_students[0].rollho = 1;
    array_students[0].age = 18;

    strncpy(array_students[1].stud_name, "Daniela", 7);
    array_students[1].rollho = 2;
    array_students[1].age = 19;

    strncpy(array_students[2].stud_name, "Helena", 6);
    array_students[2].rollho = 3;
    array_students[2].age = 17;


    for(int i = 0; i < 3; i++) {
        printf("Name: %s\n", array_students[i].stud_name);
        printf("Roll No: %d\n", array_students[i].rollho);
        printf("Age: %d\n", array_students[i].age);
    }

    return (0);
}
