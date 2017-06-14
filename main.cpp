#include <exception>
#include <iostream>
#include <algorithm>

#include "task0.h"
#include "task1.h"
#include "task2.h"

int testValue(int value, int expected)
{
	if (value != expected) {
		throw new std::runtime_error("Actual value not equal expected");
	}
	return value;
}

void doTask0()
{
	static const std::vector<Point> values = {
		{ 123.0, 48.55 },
		{ -128.1, 49.55 },
		{ 134.0, -59.1 },
		{ -134.0, -57.0 },
		{ 123.0, 49.0 },
		{ 123.0, 48.0 },
		{ 123.0, -48.55 },
		{ -128.1, 49.55 },
		{ 123.0, 49.0 }
	};
	
	std::cout << "=========================== Task 0 =============================" << std::endl;
	std::vector<Point> copyValues(values.begin(), values.end());
	std::sort(copyValues.begin(), copyValues.end(), [&](const Point& p1, const Point& p2) {
		static const Point MY_POINT = { 46.482526, 30.7233095 };
		auto diff1 = PointTools::distance(p1, MY_POINT);
		auto diff2 = PointTools::distance(p2, MY_POINT);
		return diff1 < diff2;
	});

	std::cout << "Before sorting: " << std::endl;
	PointTools::printPoints(values);
	std::cout << "After sorting: " << std::endl;
	PointTools::printPoints(copyValues);
	std::cout << "================================================================" << std::endl;
}

void doTask1()
{
	std::cout << "=========================== Task 1 =============================" << std::endl;
	std::cout << "With Recursion:" << std::endl;
	std::cout << "value = " << testValue(Pyramid::getWithRecursion(4, 2), 6) << std::endl;
	std::cout << "value = " << testValue(Pyramid::getWithRecursion(0, 0), 1) << std::endl;
	std::cout << "value = " << testValue(Pyramid::getWithRecursion(2, 1), 2) << std::endl;
	std::cout << "Without Recursion:" << std::endl;
	std::cout << "value = " << testValue(Pyramid::getWithoutRecursion(4, 2), 6) << std::endl;
	std::cout << "value = " << testValue(Pyramid::getWithoutRecursion(0, 0), 1) << std::endl;
	std::cout << "value = " << testValue(Pyramid::getWithoutRecursion(2, 1), 2) << std::endl;
	std::cout << "With Less Using Memory:" << std::endl;
	std::cout << "value = " << testValue(Pyramid::getWithLessMemory(4, 2), 6) << std::endl;
	std::cout << "value = " << testValue(Pyramid::getWithLessMemory(0, 0), 1) << std::endl;
	std::cout << "value = " << testValue(Pyramid::getWithLessMemory(2, 1), 2) << std::endl;
	std::cout << "================================================================" << std::endl;
}

void doTask2()
{
	std::cout << "=========================== Task 2 =============================" << std::endl;
	ObjectMath::Ptr object = Factory::circle(1.0);
	object->draw();
	std::cout << "perimetr:" << object->perimetr() << " area:" << object->area() << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	object = Factory::circle(4.0);
	object->draw();
	std::cout << "perimetr:" << object->perimetr() << " area:" << object->area() << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	Object::Ptr object2 = Factory::orange(10, "Spain");
	object2->draw();
	std::cout << "================================================================" << std::endl;
}

int main() {
	try {
		doTask0();
		doTask1();
		doTask2();
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	system("pause");

	return 0;
}