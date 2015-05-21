#include <iostream>
//This program calculates the statistics of a circle
class Circle
{
		private:
			double radius;
			double pi;
		public:
			Circle();
			Circle(double);
			void setRadius(double);
			double getRadius() const;
			double getDiameter()const;
			double getCircumferance() const;
			double getArea() const;
};

Circle::Circle()
{
	pi = 3.14159;
	radius = 0;
}
Circle::Circle(double r)
{
	pi = 3.14159;
	radius = r;
}

double Circle::getArea() const
{
	return pi *radius*radius;
}
//mutator function
void Circle::setRadius(double r)
{
	radius = r;
}

double Circle::getRadius() const
{
	return radius;
}
double Circle::getDiameter()const
{
	return 2 * radius;
}

double Circle::getCircumferance()const
{
	return 2 * pi * radius;
}


int main()
{
	double radius;
	std::cout << "Enter the radius of the circle" << std::endl;
	std::cin >> radius;
	Circle circl_obj(radius);
	std::cout << "The radius is " << circl_obj.getRadius() << std::endl;
	std::cout << "The circumferance of the circle is " << circl_obj.getCircumferance() << std::endl;
	std::cout << "The diameter of the circle is " << circl_obj.getDiameter() << std::endl;
	std::cout << "The area of the circle is " << circl_obj.getArea() << std::endl;
	std::cin.get();
	std::cin.get();
	Circle circ;
	Circle ci();
	return 0;
}
