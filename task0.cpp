#include "task0.h"

#include <iostream>

#include <cmath>

/**
* Значение числа Pi
*/
static const double PI_VALUE = 3.14159265358979323846;

/**
* Функция вывода Point в поток
*/
std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << "Point [LON: " << p.longitude << ", LAT: " << p.latitude << "]";
	return os;
}

/**
* Функция преобразования из градусов в радианы
*/
double PointTools::toRadians(double angdeg)
{
	return angdeg / 180.0 * PI_VALUE;
}

/**
* Функция определения расстояния между двумя координатамы в км
*/
double PointTools::distance(const Point& p1, const Point& p2) {
	static const double R = 6371e3;

	double dLat = PointTools:: toRadians(p2.latitude - p1.latitude);
	double dLng = PointTools::toRadians(p2.longitude - p1.longitude);

	double f1 = PointTools::toRadians(p1.latitude);
	double f2 = PointTools::toRadians(p2.latitude);

	double a = std::pow(std::sin(dLat / 2), 2)
		+ std::pow(std::sin(dLng / 2), 2)
		* std::cos(f1) * std::cos(f2);
	double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));

	return R * c;
}

/**
* Метод печати списка координат на консоль
*/
void PointTools::printPoints(const std::vector<Point>& points) {
	for (const Point& p : points) {
		std::cout << p << std::endl;
	}
}
