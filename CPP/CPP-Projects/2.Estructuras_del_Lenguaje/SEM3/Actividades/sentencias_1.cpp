#include<iostream>

using namespace std;

int main()
{
    int n1, n2;
    cout <<"Digite el primer numero: " <<endl;
    cin >>n1;

    cout <<"Digite el segundo numero: "<<endl;
    cin >>n2;

    if (n1 > n2)
    {
        cout <<"El primer numero es mayor que el segundo: " <<n1 <<endl;
    } else if (n1 == n2)
    {
        cout <<"Los dos numeros son iguales."<<endl <<endl;
    } else
    {
        cout <<"El segundo numero es mayor que el primero: " <<n2 <<endl;    
    }

    system("pause");
    return EXIT_SUCCESS;
}