#pragma once

#include <vector>

/**
* Определение структуры координаты
*/
struct Point {
	double longitude;
	double latitude;

};

/**
* Вспомогательный класс для расчетов
*/
class PointTools {
public:
	static double toRadians(double angdeg);
	static double distance(const Point& p1, const Point& p2);
	static void printPoints(const std::vector<Point>& points);
};
