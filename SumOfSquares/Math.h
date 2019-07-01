#pragma once
#include "array.h"

class math {
public:
	math();
	math(int start, int end);
	~math();

	integerArray sum_of_squares();
	integerArray square_of_sums();

	void set_start(int start);
	int get_start();

	void set_end(int end);
	int get_end();

private:
	integerArray m_arr;

	int m_start;
	int m_end;

	integerArray to_squares();
	void to_squares(integerArray &arr);

	//int square_of(integerArray arr);
	int sum_of(integerArray arr);
};