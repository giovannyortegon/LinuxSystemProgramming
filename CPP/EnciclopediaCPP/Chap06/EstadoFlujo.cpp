#include<iostream>
#include<climits>

using namespace std;

int main()
{
    int n = 0, estado = 0;

    cout <<"Dato (entero, cadena, CTRL + z, etc): ";
    cin >>n;

    estado = cin.rdstate();

    if (estado == ios::goodbit)
        cout <<"correcto\n";
    if ((estado & ios::eofbit) == ios::eofbit)
        cout <<"\nfin de la entrada\n";
    if ((estado & ios::failbit) == ios::failbit)
        cerr <<'\a' <<"\ndato incorrecto\n";
    if ((estado & ios::badbit) == ios::badbit)
        cerr <<'\a' <<"\nerror fatal\n";

    return (0);
}
