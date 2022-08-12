#include<iostream>

using namespace std;

int main()
{
    char nombre_apellido[30];
    char sexo;
    int edad;
    
    cout <<"Digite su nombre y apellido..."<<endl;
    cin.getline(nombre_apellido, 30);
    cout<<"Digite su edad..."<<endl;
    cin >> edad;
    cout <<"Digite su Sexo M o F..."<<endl;
    cin >> sexo;
    
    system("cls");
    
    cout <<"Su nombre es: " <<nombre_apellido <<endl;
    cout <<"Su edad es: " << edad <<" anios "<<endl;
    cout <<"Su Sexo es: " << sexo <<endl<<endl;
    
    system("pause");
    return EXIT_SUCCESS;
}
