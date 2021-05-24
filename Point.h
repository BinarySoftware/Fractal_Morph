#pragma once

class Point {
private:
	float _x;
	float _y;

public:
	Point(float x, float y) : _x(x), _y(y){};

	float x() { return _x; }
	float y() { return _y; }
};