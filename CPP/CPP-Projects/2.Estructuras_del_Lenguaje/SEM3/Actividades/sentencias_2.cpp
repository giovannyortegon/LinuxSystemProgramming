#include<iostream>

using namespace std;

int main()
{
    float nota;

    cout <<"Digite calificaciones"<<endl;
    cin >>nota;

    /*
     * Si la senttencia es mayor que cero y menor que 5 es valida
     * si no, entoces genera un error.
    */
   if (nota > 0.0 && nota < 5.0)
   {
        if (nota < 3)
            cout <<"Has REPROBADO la materia."<<endl <<endl;
        else
            cout <<"Has APROBADO la materia." <<endl <<endl;
   }
   else
        cout <<"La calificaciones digitadas no es valida." <<endl <<endl;

    system("pause");
    return EXIT_SUCCESS;
}