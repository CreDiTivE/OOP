#include "Point.h"


/* Вывод информации про объект */
void Point::display()
{
	cout << "Координата x: " << x << endl;
	cout << "Координата y: " << y << endl;
}

void Point::displayPolar()
{
	cout << "Радиальная координата: " << sqrt(this->x*this->x + this->y*this->y) << endl;
	cout << "Полярный угол : " << (x ? atan(y / x): 0) << endl;
}

/* перенос точки на расстояние dx, dy */

Point Point::transfer(float dx, float dy)
{
	return Point(x += dx, y += dy);
}

/* перегрузка операторов */

/* Перегрузка операции + */
Point Point::operator + (const Point &point)
{
	return Point(this->x + point.x, this->y + point.y);
}

/* Перегрузка операции - */
Point Point::operator - (const Point &point)
{
	return Point(this->x - point.x, this->y - point.y);
}

/* Перегрузка операции == */
const bool Point::operator == (const Point &point)
{
	return (this->x == point.x && this->y == point.y);
}

/* Перегрузка операции != */
const bool Point::operator != (const Point &point)
{
	return !(*this == point);
}

/* Перегрузка операции < */
const bool Point::operator < (Point &point)
{
	return sqrt(this->x*this->x + this->y*this->y) < sqrt(point.x*point.x + point.y*point.y);
}

/* Перегрузка операции <= */
const bool Point::operator <= (Point &point)
{
	return sqrt(this->x*this->x + this->y*this->y) <= sqrt(point.x*point.x + point.y*point.y);
}
/* Перегрузка операции > */
const bool Point::operator > (Point &point)
{
	return sqrt(this->x*this->x + this->y*this->y) > sqrt(point.x*point.x + point.y*point.y);
}

/* Перегрузка операции >= */
const bool Point::operator >= (Point &point)
{
	return sqrt(this->x*this->x + this->y*this->y) >= sqrt(point.x*point.x + point.y*point.y);
}

/* Перегрузка операции вывода в поток */
ostream& operator << (ostream &out, const Point &point)
{
	out << "Координата x: " << point.x << "; Координата y: " << point.y;
	return out;
}

/* Перегрузка операции ввода из потока */

istream& operator >> (istream &in, Point &point)
{
	cout << "Обновите координаты точки\nx: ";
	cin >> point.x;
	cout << "y: ";
	cin >> point.y;
	return in;
}

/* Деструктор */
Point::~Point()
{
}

