#pragma once

#include <vector>
#include <memory>

class Pyramid {
	using IntDynamicArray = std::vector<int>;
public:

	/**
	* Функция для получения значения в точке [i, j] пирамиды с использованием рекурсии
	* @param i значение индекса по оси абцисс
	* @param j значение индекса по оси ординат
	* @return значение в точке [i, j]
	*/
	static int getWithRecursion(unsigned int i, unsigned int j);

	/**
	* Функция для получения значения в точке [i, j] пирамиды без использованием рекурсии
	* @param i значение индекса по оси абцисс
	* @param j значение индекса по оси ординат
	* @return значение в точке [i, j]
	*/
	static int getWithoutRecursion(unsigned int i, unsigned int j);

	/**
	* Функция для получения значения в точке [i, j] пирамиды с минимальным использованием памяти
	* @param i значение индекса по оси абцисс
	* @param j значение индекса по оси ординат
	* @return значение в точке [i, j]
	*/
	static int getWithLessMemory(unsigned int i, unsigned int j);

private:

	/**
	* Функция для создания квадратной матрицы
	* @param size размер матрицы
	* @param value значение по-умолчанию для каждой точки
	* @return квадратная матрица
	*/
	static std::vector<IntDynamicArray> createSquareArray(std::size_t size, int value = -1);

	/**
	* Функция вычисления Binomial Coefficient
	* @param i значение индекса по оси абцисс
	* @param j значение индекса по оси ординат
	* @return значение коэффициента
	*/
	static int binomialCoeff(unsigned int i, unsigned int j);

};