#pragma once
#include "array.h"

class Math {
public:
	Math();
	Math(int start, int end);
	~Math();

	integerArray* sum_of_squares();
	integerArray* square_of_sums();

	void set_start(int start);
	int get_start();

	void set_end(int end);
	int get_end();

private:
	integerArray* m_arr;

	int m_start;
	int m_end;

	bool m_start_set;
	bool m_end_set;

	integerArray* to_squares();
	void to_squares(integerArray* arr);

	//int square_of(integerArray arr);
	int sum_of(integerArray* const arr);

	void set_values();
};