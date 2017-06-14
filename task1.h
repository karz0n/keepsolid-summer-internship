#pragma once

#include <vector>
#include <memory>

class Pyramid {
	using IntDynamicArray = std::vector<int>;
public:

	/**
	* ������� ��� ��������� �������� � ����� [i, j] �������� � �������������� ��������
	* @param i �������� ������� �� ��� ������
	* @param j �������� ������� �� ��� �������
	* @return �������� � ����� [i, j]
	*/
	static int getWithRecursion(unsigned int i, unsigned int j);

	/**
	* ������� ��� ��������� �������� � ����� [i, j] �������� ��� �������������� ��������
	* @param i �������� ������� �� ��� ������
	* @param j �������� ������� �� ��� �������
	* @return �������� � ����� [i, j]
	*/
	static int getWithoutRecursion(unsigned int i, unsigned int j);

	/**
	* ������� ��� ��������� �������� � ����� [i, j] �������� � ����������� �������������� ������
	* @param i �������� ������� �� ��� ������
	* @param j �������� ������� �� ��� �������
	* @return �������� � ����� [i, j]
	*/
	static int getWithLessMemory(unsigned int i, unsigned int j);

private:

	/**
	* ������� ��� �������� ���������� �������
	* @param size ������ �������
	* @param value �������� ��-��������� ��� ������ �����
	* @return ���������� �������
	*/
	static std::vector<IntDynamicArray> createSquareArray(std::size_t size, int value = -1);

	/**
	* ������� ���������� Binomial Coefficient
	* @param i �������� ������� �� ��� ������
	* @param j �������� ������� �� ��� �������
	* @return �������� ������������
	*/
	static int binomialCoeff(unsigned int i, unsigned int j);

};