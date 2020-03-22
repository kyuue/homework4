#include "Triangle.h"

#include <iostream>

const std::map<Triangle::Color, string>  Triangle::colorToStringMap = {
	{Triangle::Color::RED, "Red"},
{Triangle::Color::BLACK, "Black"},
{Triangle::Color::BLUE, "Blue"},
{Triangle::Color::GREEN, "Green"},
{Triangle::Color::PINK, "Pink"},
{Triangle::Color::WHITE, "White"},
};

Triangle::Triangle(const Point & a, const Point & b, const Point & c, const Color & color)
{
	this->setA(a);

	this->setB(b);

	this->setC(c);

	this->color = color;

	if (!this->isValid())
		throw invalid_argument("invalid tri");
}

Triangle::Triangle(const vector<Point>& pts, const Color & color)
{
	this->setA(pts[0]);

	this->setB(pts[1]);

	this->setC(pts[2]);

	this->color = color;

	if (!this->isValid())
		throw invalid_argument("invalid tri");
}

Triangle::Triangle(const array<Point, NUMBER_OF_CORNERS>& pts, const Color & color)
{
	this->setA(pts[0]);

	this->setB(pts[1]);

	this->setC(pts[2]);

	this->color = color;

	if (!this->isValid())
		throw invalid_argument("invalid tri");
}


Point Triangle::getA() const noexcept
{
	return this->a;
}

Point Triangle::getB() const noexcept
{
	return this->b;
}

Point Triangle::getC() const noexcept
{
	return this->c;
}

Triangle::Color Triangle::getColor() const noexcept
{
	return this->color;
}

string Triangle::getColorAsString() const noexcept
{
	return colorToStringMap.at(color);
}

double Triangle::getPerimeter() const noexcept
{
	float firstEdge = this->getA().distanceTo(this->getB());

	float secondEdge = this->getB().distanceTo(this->getC());

	float thirdEdge = this->getC().distanceTo(this->getA());

	return firstEdge + secondEdge + thirdEdge;
}

bool Triangle::setA(const Point & pt)
{
	this->a.x = pt.x;

	this->a.y = pt.y;

	return true;
}

bool Triangle::setB(const Point & pt)
{
	this->b.x = pt.x;

	this->b.y = pt.y;

	return true;
}

bool Triangle::setC(const Point & pt)
{
	this->c.x = pt.x;

	this->c.y = pt.y;

	return true;
}

bool Triangle::isValid() const
{
	float firstEdge = this->getA().distanceTo(this->getB());

	float secondEdge = this->getB().distanceTo(this->getC());

	float thirdEdge = this->getC().distanceTo(this->getA());

	return (thirdEdge < firstEdge + secondEdge && thirdEdge > abs(firstEdge - secondEdge))
		&& (secondEdge < firstEdge + thirdEdge && secondEdge > abs(firstEdge - thirdEdge))
		&& (firstEdge < secondEdge + thirdEdge && firstEdge > abs(secondEdge - thirdEdge));
}

double Triangle::printInfo() const noexcept
{
	cout << "Triangle\n";
	cout << "Number of points: " << NUMBER_OF_CORNERS << endl;
	cout << "Points: ";

	for (auto point : this->pts)
	{
		cout << point.toString() << ", ";
	}

	cout << endl;

	cout << this->getPerimeter() << std::endl;

	cout << this->getColorAsString() << std::endl;

	return this->getPerimeter();
}
