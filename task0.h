#pragma once

#include <vector>

/**
* ����������� ��������� ����������
*/
struct Point {
	double longitude;
	double latitude;

};

/**
* ��������������� ����� ��� ��������
*/
class PointTools {
public:
	static double toRadians(double angdeg);
	static double distance(const Point& p1, const Point& p2);
	static void printPoints(const std::vector<Point>& points);
};
