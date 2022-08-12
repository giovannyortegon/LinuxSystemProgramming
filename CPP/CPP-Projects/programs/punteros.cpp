#include<iostream>

using namespace std;

int main()
{
	int id = 20;
	int *pt_id;
	int *pt_id2;

	pt_id = &id;
	pt_id2 = pt_id;

	cout << "Contenido id: " << id << endl;
	cout << "Address id: " << &id << endl;
	cout << "Contenido de id desde puntero id: "<< *pt_id << endl;
	cout << "Contenido puntero id: "<< pt_id << endl;
	cout << "Address  puntero id: "<< &pt_id << endl;
	cout << "Contenido puntero pt_id2: "<< pt_id2 << endl;
	cout << "Contenido puntero pt_id2: "<< *pt_id2 << endl;

	return (0);
}
