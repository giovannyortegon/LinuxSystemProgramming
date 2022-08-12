#include<iostream>
#include<iomanip>


class CGrados
{
	private:
		float gradosC;		// grados centigrados
	public:
		void AsignarCentigrados(float gC);
		float ObtenerFahrenheit() const;
		float ObtenerCentigrados() const;
};
