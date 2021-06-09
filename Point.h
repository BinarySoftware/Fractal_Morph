#pragma once
#include <vector>

class Point {
private:
	float _x;
	float _y;
	const wxPen* _pen;

public:
	Point(float x, float y, const wxPen* p) : _x(x), _y(y), _pen(p){};

	float x()		   { return _x; }
	float y()		   { return _y; }
	const wxPen* pen() { return _pen; }
};

typedef std::vector<Point> Points;