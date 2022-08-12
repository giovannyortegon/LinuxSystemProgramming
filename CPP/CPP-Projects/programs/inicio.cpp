#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string var("Hola");

    cout<<var.at(0)<<endl;
	cout<<var.length()<<endl;
	cout<<"Hola Mundo"<<endl;


	enum Semaforo {ROJO, AMARILLO, VERDE};

	Semaforo semaforo1;
	semaforo1 = ROJO;

	cout<<semaforo1<<endl;

	cout<<"********************* vectors ************************"<<endl;
	vector<float> ingresos;

	ingresos.push_back(1400);
	ingresos.push_back(1600);
	ingresos.push_back(1200);

	for (int i =0; i < 3; i++)
		//cout<<ingresos[i]<<endl;
		cout<<ingresos.at(i)<<endl;

    return 0;
}
