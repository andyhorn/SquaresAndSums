#include "Math.h"

math::math() {
	
}

math::math(int start, int end) {
	m_start = start;
	m_end = end;
}

math::~math() {

}

void math::set_start(int start) {
	m_start = start;
}

void math::set_end(int end) {
	m_end = end;
}

int math::get_start() {
	return m_start;
}

int math::get_end() {
	return m_end;
}

integerArray math::square_of_sums() {
	integerArray digits, found_numbers;
	int found_size = 0, length = 0, sum = 0;

	// For each value in the array
	for (int i = 0; i < m_arr.get_size(); i++) {
		// Get the digits of the current integer
		digits = m_arr.get_digits(i);

		// Get the sum of the digits
		sum = sum_of(digits);

		// Square the sum
		int square = sum * sum;

		// If the square is the same as the original value
		if (square == m_arr[i]) {
			// Add it to our collection
			found_numbers.add(i);
		}
	}

	return found_numbers;
}

integerArray math::sum_of_squares() {
	//int *digits, *found_numbers = nullptr, found_size = 0, length = 0, sum = 0;

	integerArray digits, found_numbers;
	int found_size = 0, length = 0, sum = 0;

	// For each value in the arry
	for (int i = 0; i < m_arr.get_size(); i++) {
		// Get the digits of the current integer
		digits = m_arr.get_digits(i);

		// Square each digit
		to_squares(digits);

		// Find the sum of all the values
		sum = sum_of(digits);

		// If the sum is equal to the original value
		if (sum == m_arr[i]) {
			// Save the original value to our collection
			found_numbers.add(i);
		}
	}

	return found_numbers;
}

integerArray math::to_squares() {
	// Get a new integerArray object
	integerArray square_arr(m_arr.get_size());

	// For each value in this array
	for (int i = 0; i < m_arr.get_size(); i++) {
		// Get the value
		int val = m_arr[i];
		// Square it
		val = val * val;
		// Save it to the square array
		square_arr[i] = val;
	}

	return square_arr;
}

void math::to_squares(integerArray &arr) {
	// Get the size of the incoming array
	int size = arr.get_size(), val = 0;

	// For each value in the array
	for (int i = 0; i < size; i++) {
		// Get the current value
		val = arr[i];

		// Square it
		val = val * val;

		// Save it back to the array
		arr[i] = val;
	}
}

int math::sum_of(integerArray arr) {
	// Get the size of the incoming array
	int size = arr.get_size(), sum = 0;

	// For each value in the array
	for (int i = 0; i < size; i++) {
		// Add it to the sum value
		sum += arr[i];
	}

	return sum;
}