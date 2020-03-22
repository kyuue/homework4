#include "Quadrilateral.h"

#include <iostream>

const std::map<Quadrilateral::Color, string>  Quadrilateral::colorToStringMap = {
	{Quadrilateral::Color::RED, "Red"},
{Quadrilateral::Color::BLACK, "Black"},
{Quadrilateral::Color::BLUE, "Blue"},
{Quadrilateral::Color::GREEN, "Green"},
{Quadrilateral::Color::WHITE, "White"},
};

Quadrilateral::Quadrilateral(const Point & a, const Point & c, const Color & color)
{
	this->setA(a);

	this->setB(Point(a.x, c.y)); // may destroy

	this->setC(c);

	this->setD(Point(c.x, a.y)); // may destroy

	this->color = color;

	if (!this->isValid())
		throw invalid_argument("invalid quad");
}

Quadrilateral::Quadrilateral(const Point & a, double width, double height, const Color & color)
{
	this->setA(a);

	this->setB(Point(a.x, a.y + height)); // may destroy

	this->setC(Point(a.x + width, a.x + height)); // may destroy

	this->setD(Point(a.x + width, a.y)); // may destroy

	this->color = color;

	if (!this->isValid())
		throw invalid_argument("invalid quad");
}

Quadrilateral::Quadrilateral(const Point & a, const Point & b, const Point & c, const Point & d, const Color & color)
{
	this->setA(a);

	this->setB(b);

	this->setC(c);

	this->setD(d);

	this->color = color;

	if (!this->isValid())
		throw invalid_argument("invalid quad");
}

Quadrilateral::Quadrilateral(const array<Point, NUMBER_OF_CORNERS>& pts, const Color & color)
{
	this->setA(pts[0]);

	this->setB(pts[1]);

	this->setC(pts[2]);

	this->setD(pts[3]);

	this->color = color;

	if (!this->isValid())
		throw invalid_argument("invalid quad");
}

Point Quadrilateral::getA() const noexcept
{
	return this->a;
}

Point Quadrilateral::getB() const noexcept
{
	return this->b;
}

Point Quadrilateral::getC() const noexcept
{
	return this->c;
}

Point Quadrilateral::getD() const noexcept
{
	return this->d;
}

Quadrilateral::Color Quadrilateral::getColor() const noexcept
{
	return this->color;
}

string Quadrilateral::getColorAsString() const noexcept
{
	return colorToStringMap.at(this->color);
}

double Quadrilateral::getPerimeter() const noexcept
{
	float firstEdge = this->getA().distanceTo(this->getB());

	float secondEdge = this->getB().distanceTo(this->getC());

	float thirdEdge = this->getC().distanceTo(this->getD());

	float fourthEdge = this->getD().distanceTo(this->getA());

	return firstEdge + secondEdge + thirdEdge + fourthEdge;
}

bool Quadrilateral::isValid() const
{
	return this->getA().y != this->getC().y && this->getB().y != this->getD().y;
}

bool Quadrilateral::setA(const Point & pt)
{
	this->a.x = pt.x;

	this->a.y = pt.y;

	return true;
}

bool Quadrilateral::setB(const Point & pt)
{
	this->b.x = pt.x;

	this->b.y = pt.y;

	return true;
}

bool Quadrilateral::setC(const Point & pt)
{
	this->c.x = pt.x;

	this->c.y = pt.y;

	return true;
}

bool Quadrilateral::setD(const Point & pt)
{
	this->d.x = pt.x;

	this->d.y = pt.y;

	return true;
}

double Quadrilateral::printInfo() const noexcept
{
	cout << "Rectangle\n";
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
