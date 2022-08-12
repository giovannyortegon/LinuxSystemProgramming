#include<iostream>

using namespace std;

// Class definition
class Circle
{
	private:
		double radius;

	public:
		Circle (double radius);		// Parameter constructor
		Circle ();					// Default Constructor
		~Circle();					// Destructor

		Circle (const Circle &circle);	// Copy Constructor

		void setRadius(double radius);	// Mutator
		double getRadius() const;		// Accessor
		double getArea() const;			// Accessor
		double getPerimeter() const;	// Accessor
};

// Definition of parameter constructor
Circle::Circle(double rds)
:radius(rds)
{
	cout <<"The parameter constructor was called. " <<radius;
	cout <<endl;
}

// Definition of default constructor
Circle::Circle()
:radius(0.0)
{
	cout <<"The default constructor was called. " <<radius;
	cout <<endl;
}

// Default of copy constructor
Circle::Circle(const Circle &circle)
:radius(circle.radius)
{
	cout <<"The copy constructor was called. " <<radius;
	cout <<endl;
}

// Definition of destructor
Circle::~Circle()
{
	cout <<"The destructor was called for circle with radius.";
	cout <<endl;
}

// Definition of setRadius member function
void Circle::setRadius(double value)
{
	radius = value;
}

// Definition getRadius member function
double Circle::getRadius() const
{
	return radius;
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

/*
 * Aplication: create three objects of class Circle
 */
int main()
{
	Circle circle1(5.2);

	// Instantiation of circle1 and applying operation on it
	cout <<"Radius: " <<circle1.getRadius() <<endl;
	cout <<"Area: " <<circle1.getArea() <<endl;
	cout <<"Perimeter: " <<circle1.getPerimeter() <<endl <<endl;

	// Instantiation of circle3 and applying operations on it
	Circle circle2(circle1);
	cout <<"Radius: " <<circle2.getRadius() <<endl;
	cout <<"Area: " <<circle2.getArea() <<endl;
	cout <<"Perimeter: " <<circle2.getPerimeter() <<endl <<endl;

	// Instantiation of circle3 and applying operation on it
	Circle circle3;
//	circle3.setRadius(10.5);
	cout <<"Radius: " <<circle3.getRadius() <<endl;
	cout <<"Area: " <<circle3.getArea() <<endl;
	cout <<"Perimeter: " <<circle3.getPerimeter() <<endl <<endl;

	// Calls to destructors Occur here
	return (0);
}
