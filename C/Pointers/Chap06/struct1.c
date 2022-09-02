#include<stdio.h>

int main() {
    struct date {
        int day;
        int month;
        int year;
    };

    struct date current;

    current.day = 1;
    current.month = 11;
    current.year = 2022;

    printf("Date: %d-%d-%d\n", current.day, current.month, current.year);
    
    return (0);
}