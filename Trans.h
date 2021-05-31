#pragma once
#include "Point.h"

class Trans {
private:
	float _a, _b, _c, _d, _e, _f;

public:
	Trans(float a, float b, float c, float d, float e, float f) : _a(a), _b(b), _c(c), _d(d), _e(e), _f(f) {};

	Point calculate(Point previous) {
		float x = _a * previous.x() + _b * previous.y() + _e;
		float y = _c * previous.x() + _d * previous.y() + _f;
		return Point(x, y);
	}
};