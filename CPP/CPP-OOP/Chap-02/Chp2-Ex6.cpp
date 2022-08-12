#include<iostream>
#include<cmath>

using namespace std;

const float PI = 3.14159;

class Circle
{
	public:
		float radius;
		float area;
};

class Rectangle
{
	public:
		float length;
		float width;
		float area;
};

void display(Circle);
void display(Rectangle);

int main()
{
	Circle myCircle;
	Rectangle myRect;
	Rectangle mySquare;

	myCircle.radius = 5.0;
	myCircle.area = PI * pow(myCircle.radius, 2.0);

	myRect.length = 2.0;
	myRect.width = 4.0;
	myRect.area = mySquare.length * mySquare.width;

	display(myCircle);
	display(myRect);
	display(mySquare);

	return (0);
}
void display(Circle c)
{
	cout <<"Circle with radius " <<c.radius;
	cout <<" has an area of " <<c.area <<endl;
}
void display (Rectangle r)
{
	cout <<"Rectangle with length " <<r.length;
	cout <<" and width " <<r.width;
	cout <<" has an area of " <<r.area <<endl;
}
