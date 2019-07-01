#pragma once

enum OPS {
	SUM_OF_SQUARES,
	SQUARE_OF_SUMS
};

void run_operation(int operation, int start, int end);
int *square_of_sums(int start, int end, int &found);
int *sum_of_squares(int start, int end, int &found);