#pragma once

#include <iostream>
#include <memory>
#include <string>

/**
* Значение числа Pi
*/
static const double PI_VALUE = 3.14159265358979323846;

//=============================================

//
// Базовый класс фигуры
//
class Object {
public:
	typedef std::shared_ptr<Object> Ptr;

	virtual void draw() = 0;
};

//=============================================

//
// Базовый класс фигуры с методами вычисления площади и периметра
//
class ObjectMath : public Object {
public:
	typedef std::shared_ptr<ObjectMath> Ptr;

	virtual double area() = 0;
	virtual double perimetr() = 0;
};

//=============================================

//
// Класс фигуры треугольника
//
class Triangle : public ObjectMath {
	unsigned int base;
	unsigned int height;
public:
	Triangle(unsigned int b, unsigned int h)
		: base(b), height(h)
	{ }

	void draw() override;

	double area() override;
	double perimetr() override;
};

void Triangle::draw() {
	for (unsigned int i = 1; i <= base; ++i) {
		for (unsigned int j = 1; j <= i; ++j) {
			std::cout << "* ";
		}
		std::cout << std::endl;
	}
}

double Triangle::area()
{
	return 0.5 * base * height;
}

double Triangle::perimetr()
{
	double c = std::sqrt(std::pow(base, 2) + std::pow(height, 2));
	return base + height + c;
}

//=============================================

//
// Класс фигуры квадрата
//
class Square : public ObjectMath {
	unsigned int length;
public:
	Square(unsigned int l)
		: length(l)
	{ }

	void draw() override;

	double area() override;
	double perimetr() override;
};

void Square::draw() {
	unsigned int pos = 1;
	unsigned int chars = length * length;
	while (pos <= chars) {
		std::cout << "* ";
		if (pos % length == 0)
			std::cout << std::endl;
		pos++;
	}
}

double Square::area()
{
	return std::pow(length, 2);
}

double Square::perimetr()
{
	return 4.0 * length;
}

//=============================================

//
// Класс фигуры круга
//
class Circle : public ObjectMath {
	double radius;
public:
	Circle(double r)
		: radius(r)
	{ }

	void draw() override;

	double area() override;
	double perimetr() override;
};

void Circle::draw() {
	double r_in = radius - 0.4;
	double r_out = radius + 0.4;

	for (double y = radius; y >= -radius; --y) {
		for (double x = -radius; x < r_out; x += 0.5) {
			double value = x * x + y * y;
			if (value >= r_in * r_in && value <= r_out * r_out) {
				std::cout << '*';
			}
			else {
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
}

double Circle::area()
{
	return PI_VALUE * std::pow(radius, 2);
}

double Circle::perimetr()
{
	return 2.0 * PI_VALUE * radius;
}

//=============================================

//
// Класс объекта яблока
//
class Apple : public Object {
	double weight;
	std::string country;
public:
	Apple(double w, const std::string& c)
		: weight(w), country(c)
	{ }

	void draw() override;
};

void Apple::draw() {
	std::cout
		<< "I'm an apple, my weight is " << weight
		<< " and I'm from " << country << std::endl;
}

//=============================================

//
// Класс объекта апельсина
//
class Orange : public Object {
	double weight;
	std::string country;
public:
	Orange(double w, const std::string& c)
		: weight(w), country(c)
	{ }

	void draw() override;
};

void Orange::draw() {
	std::cout
		<< "I'm an orange, my weight is " << weight
		<< " and I'm from " << country << std::endl;
}

//=============================================

//
// Класс объекта дома
//
class House : public Object {
	unsigned int floors;
	std::string address;
public:
	House(unsigned int f, const std::string& a)
		: floors(f), address(a)
	{ }

	void draw() override;
};

void House::draw() {
	std::cout
		<< "I'm a house in " << address << " address with "
		<< floors << " floors";
}

//=============================================

//
// Класс фабрики для создания объектов
//
class Factory {
public:
	static ObjectMath::Ptr triangle(unsigned int base, unsigned int height)
	{
		return std::make_shared<Triangle>(base, height);
	}

	static ObjectMath::Ptr square(unsigned int length)
	{
		return std::make_shared<Square>(length);
	}

	static ObjectMath::Ptr circle(double radius)
	{
		return std::make_shared<Circle>(radius);
	}

	static Object::Ptr apple(double weight, const std::string& country)
	{
		return std::make_shared<Apple>(weight, country);
	}

	static Object::Ptr orange(double weight, const std::string& country)
	{
		return std::make_shared<Orange>(weight, country);
	}

	static Object::Ptr house(unsigned int floors, const std::string& address)
	{
		return std::make_shared<House>(floors, address);
	}
};

