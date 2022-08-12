class Circulo
{
	public:
		double CalcArea();
		void setRadio(double ra);
		double getRadio();
	private:
		double radio;
};

double Circulo::CalcArea()
{
	return 3.1416 * radio * radio;
}

void Circulo::setRadio(double ra)
{
	radio = ra;
}

double Circulo::getRadio()
{
	return radio;
}
