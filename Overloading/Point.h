#include <iostream>
using namespace std;

class Point
{
private:
	float x;
	float y;

public:
	Point(float cur_x, float cur_y) : x(cur_x), y(cur_y) {}; // constructor with parameters
	Point() : x(0), y(0) {};								 // default constructor
	Point(const Point& p) : x(p.x), y(p.y) {};				 // copy constructor
	~Point();												 // destructor

	void  set_x(float cur_x) { x = cur_x; }; // set x
	float get_x() const { return x; };		 // get x

	void  set_y(float cur_y) { x = cur_y; }; // set y
	float get_y() const { return y; };		 // get y

	Point transfer(float dx, float dy);

	Point operator + (const Point &point);
	Point operator - (const Point &point);
	const bool operator == (const Point &point);
	const bool operator != (const Point &point);
	const bool operator < (Point &point);
	const bool operator <= (Point &point);
	const bool operator > (Point &point);
	const bool operator >= (Point &point);
	friend ostream& operator << (ostream&, const Point &point);
	friend istream& operator >> (istream&, Point &point);

	void display();
	void displayPolar();
};
