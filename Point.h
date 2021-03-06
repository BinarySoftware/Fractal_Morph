#pragma once
#include <vector>

/// <summary>
/// Klasa przechowująca punkt w układzie kartezjańskim, razem z jego kolorem wyświetlania.
/// </summary>
class Point {
private:
	float _x;
	float _y;
	const wxPen* _pen;

public:
	/// <summary>
	/// Konstruktor główny.
	/// </summary>
	/// <param name="x">Położenie na osi X</param>
	/// <param name="y">Położenie na osi Y</param>
	/// <param name="p">Kolor rysowania</param>
	Point(float x, float y, const wxPen* p) : _x(x), _y(y), _pen(p) {};

	float x() { return _x; }
	float y() { return _y; }
	const wxPen* pen() { return _pen; }
};

typedef std::vector<Point> Points;