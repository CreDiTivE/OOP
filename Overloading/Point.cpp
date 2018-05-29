#include "Point.h"


/* ����� ���������� ��� ������ */
void Point::display()
{
	cout << "���������� x: " << x << endl;
	cout << "���������� y: " << y << endl;
}

void Point::displayPolar()
{
	cout << "���������� ����������: " << sqrt(this->x*this->x + this->y*this->y) << endl;
	cout << "�������� ���� : " << (x ? atan(y / x): 0) << endl;
}

/* ������� ����� �� ���������� dx, dy */

Point Point::transfer(float dx, float dy)
{
	return Point(x += dx, y += dy);
}

/* ���������� ���������� */

/* ���������� �������� + */
Point Point::operator + (const Point &point)
{
	return Point(this->x + point.x, this->y + point.y);
}

/* ���������� �������� - */
Point Point::operator - (const Point &point)
{
	return Point(this->x - point.x, this->y - point.y);
}

/* ���������� �������� == */
const bool Point::operator == (const Point &point)
{
	return (this->x == point.x && this->y == point.y);
}

/* ���������� �������� != */
const bool Point::operator != (const Point &point)
{
	return !(*this == point);
}

/* ���������� �������� < */
const bool Point::operator < (Point &point)
{
	return sqrt(this->x*this->x + this->y*this->y) < sqrt(point.x*point.x + point.y*point.y);
}

/* ���������� �������� <= */
const bool Point::operator <= (Point &point)
{
	return sqrt(this->x*this->x + this->y*this->y) <= sqrt(point.x*point.x + point.y*point.y);
}
/* ���������� �������� > */
const bool Point::operator > (Point &point)
{
	return sqrt(this->x*this->x + this->y*this->y) > sqrt(point.x*point.x + point.y*point.y);
}

/* ���������� �������� >= */
const bool Point::operator >= (Point &point)
{
	return sqrt(this->x*this->x + this->y*this->y) >= sqrt(point.x*point.x + point.y*point.y);
}

/* ���������� �������� ������ � ����� */
ostream& operator << (ostream &out, const Point &point)
{
	out << "���������� x: " << point.x << "; ���������� y: " << point.y;
	return out;
}

/* ���������� �������� ����� �� ������ */

istream& operator >> (istream &in, Point &point)
{
	cout << "�������� ���������� �����\nx: ";
	cin >> point.x;
	cout << "y: ";
	cin >> point.y;
	return in;
}

/* ���������� */
Point::~Point()
{
}

