#include "task1.h"

/**
* ћаксимальное значение индекса по ос€м
*/
static const int MAX_INDEX_VALUE = 16384;

/**
* «начение точки по-умолчанию за пределами пирамиды
*/
static const int OUT_OF_RANGE_VALUE = 0;

int Pyramid::getWithRecursion(unsigned int i, unsigned int j)
{
	if (i > MAX_INDEX_VALUE || j > MAX_INDEX_VALUE)
		throw new std::invalid_argument("Index value too large");

	if (j > i)
		return OUT_OF_RANGE_VALUE;
	if (j == 0 || i == j)
		return 1;
	if (j < 0)
		return 0;

	return getWithRecursion(i - 1, j - 1) + getWithRecursion(i - 1, j);
}

int Pyramid::getWithoutRecursion(unsigned int i, unsigned int j) {
	if (i > MAX_INDEX_VALUE || j > MAX_INDEX_VALUE)
		throw new std::invalid_argument("Index value too large");

	if (j > i)
		return OUT_OF_RANGE_VALUE;
	if (i == 0 || j == 0)
		return 1;

	auto values = Pyramid::createSquareArray(i + 1, 0);
	for (unsigned int k = 0; k <= i; ++k) {
		int C = 1;
		for (unsigned int m = 0; m <= k; ++m) {
			if (k > 0 && m > 0)
				C = values[k - 1][m - 1] + values[k - 1][m];
			values[k][m] = C;
		}
	}

	return values[i][j];
}

int Pyramid::getWithLessMemory(unsigned int i, unsigned int j) {
	if (i > MAX_INDEX_VALUE || j > MAX_INDEX_VALUE)
		throw new std::invalid_argument("Index value too large");

	if (j > i)
		return OUT_OF_RANGE_VALUE;
	if (i == 0 || j == 0)
		return 1;

	return Pyramid::binomialCoeff(i, j);
}

std::vector<Pyramid::IntDynamicArray> Pyramid::createSquareArray(std::size_t size, int value /*= -1*/)
{
	if (size > MAX_INDEX_VALUE * MAX_INDEX_VALUE)
		throw new std::invalid_argument("Size for dynamic array too large");

	std::vector<IntDynamicArray> output;
	for (unsigned int i = 0; i < size; ++i) {
		IntDynamicArray array(size, value);
		output.push_back(std::move(array));
	}
	return std::move(output);
}


int Pyramid::binomialCoeff(unsigned int i, unsigned int j)
{
	if (j > i - j)
		j = i - j;

	int output = 1;

	for (unsigned int k = 0; k < j; ++k) {
		output *= (i - k);
		output /= (k + 1);
	}

	return output;
}