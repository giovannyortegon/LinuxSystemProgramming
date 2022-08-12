#include <iostream>
using namespace std;

int main(){
   int entero1 = 20;
   int entero2 = 7;
   float num1 = 2.1;
   float num2 = 8.0;

   int suma = entero1 + entero2;
   float multiplicacion = num1 * num2;
   int divisionEnteros = entero1 / entero2;
   int modulo = entero1 % entero2;
   float division = entero2 / num2;

   cout << suma << endl << multiplicacion << endl;
   cout << divisionEnteros << endl << modulo << endl << division;

   return 0;
}
