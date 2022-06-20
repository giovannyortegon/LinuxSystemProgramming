#include<stdio.h>

char * nombre_mes(unsigned int mm);

int main() {
    char * m = nombre_mes(8);

    printf("\nMes: %s\n", m);
}

char * nombre_mes(unsigned int mm) {
    static char * mes[] = {
        "Mes no correcto", "enero", "febrero", "marzo",
        "abril", "mayo", "junio", "julio", "agosto",
        "septiembre", "octubre", "noviembre", "diciembre"
    };

    return ((mm > 0 && mm <= 12) ? mes[mm] : mes[0]);
}

