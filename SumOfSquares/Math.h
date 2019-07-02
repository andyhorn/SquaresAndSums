#pragma once
#include "array.h"

class Math {
public:
	Math();
	Math(int start, int end);
	~Math();

	IntegerArray* sum_of_squares();
	IntegerArray* square_of_sums();

	void set_start(int start);
	int get_start();

	void set_end(int end);
	int get_end();

private:
	IntegerArray* m_arr;

	int m_start;
	int m_end;

	bool m_start_set;
	bool m_end_set;

	IntegerArray* to_squares();
	void to_squares(IntegerArray* arr);

	//int square_of(IntegerArray arr);
	int sum_of(IntegerArray* const arr);

	void set_values();
};