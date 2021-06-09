#pragma once
#include <vector>

/// <summary>
/// Klasa przechowuj�ca punkt w uk�adzie kartezja�skim, razem z jego kolorem wy�wietlania.
/// </summary>
class Point {
private:
	float _x;
	float _y;
	const wxPen* _pen;

public:
	/// <summary>
	/// Konstruktor g��wny.
	/// </summary>
	/// <param name="x">Po�o�enie na osi X</param>
	/// <param name="y">Po�o�enie na osi Y</param>
	/// <param name="p">Kolor rysowania</param>
	Point(float x, float y, const wxPen* p) : _x(x), _y(y), _pen(p) {};

	float x() { return _x; }
	float y() { return _y; }
	const wxPen* pen() { return _pen; }
};

typedef std::vector<Point> Points;