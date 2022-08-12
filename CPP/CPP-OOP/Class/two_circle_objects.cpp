#include<iostream>

using namespace std;

class Circle
{
	private:
		double radius;

	public:
		double getRadius() const;
		double getArea() const;
		double getPerimeter() const;
		void setRadius(double value);
};
// Definition of getRadius member function
double Circle::getRadius() const
{
	return (radius);
}
// Definition of getArea member function
double Circle::getArea() const
{
	const double PI = 3.14;
	return (PI * radius * radius);
}
// Definition of getPerimeter member function
double Circle::getPerimeter() const
{
	const double PI = 3.14;
	return (2 * PI * radius);
}
// Definition of  getArea member function
void Circle::setRadius(double value)
{
	radius = value;
}
int main()
{
	cout <<"Circle 1: "<<endl;
	Circle circle1;
	circle1.setRadius(10.0);

	cout <<"Radius: " <<circle1.getRadius() <<endl;
	cout <<"Area: " <<circle1.getArea() <<endl;
	cout <<"Perimeter: " <<circle1.getPerimeter() <<endl <<endl;

	// Creating second circle and applying member function
	cout <<"Circle 2: " <<endl;
	Circle circle2;
	circle2.setRadius(20.0);

	cout <<"Radius: " <<circle2.getRadius() <<endl;
	cout <<"Area: " <<circle2.getArea() <<endl;
	cout <<"Perimeter: " <<circle2.getPerimeter() <<endl <<endl;

	return (0);
}
