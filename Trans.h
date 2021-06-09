#pragma once
#include "Point.h"

class Trans {
private:
	float _a, _b, _c, _d, _e, _f;
	const wxPen* _pen;

public:
	Trans(float a, float b, float c, float d, float e, float f, const wxPen * p) : _a(a), _b(b), _c(c), _d(d), _e(e), _f(f), _pen(p) {};

	Point calculate(Point previous) {
		float x = _a * previous.x() + _b * previous.y() + _e;
		float y = _c * previous.x() + _d * previous.y() + _f;
		return Point(x, y, _pen);
	}

	const wxPen* pen() { return _pen; }
};