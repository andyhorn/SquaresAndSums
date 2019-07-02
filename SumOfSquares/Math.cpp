#include "Math.h"

Math::Math() {
	m_start_set = false;
	m_end_set = false;
	m_arr = new IntegerArray();
}

Math::Math(int start, int end) {
	m_start = start;
	m_end = end;
	m_start_set = true;
	m_end_set = true;

	int low = start < end ? start : end;
	int high = start < end ? end : start;

	m_arr = new IntegerArray();
	m_arr->set_size(high - low);

	set_values();
}

Math::~Math() {
	delete m_arr;
}

void Math::set_start(int start) {
	m_start = start;
	m_start_set = true;
	set_values();
}

void Math::set_end(int end) {
	m_end = end;
	m_end_set = true;
	set_values();
}

int Math::get_start() {
	return m_start;
}

int Math::get_end() {
	return m_end;
}

IntegerArray* Math::square_of_sums() {

	if (!m_start_set || !m_end_set) {
		throw "Error: Start and End values required";
	}

	IntegerArray *digits, *found_numbers = new IntegerArray();
	int found_size = 0, length = 0, sum = 0;

	// For each value in the array
	for (int i = 0; i < m_arr->get_size(); i++) {
		// Get the digits of the current integer
		digits = m_arr->get_digits(i);

		// Get the sum of the digits
		sum = sum_of(digits);

		// Square the sum
		int square = sum * sum;

		// If the square is the same as the original value
		if (square == (*m_arr)[i]) {
			// Add it to our collection
			found_numbers->add(i);
		}

		delete digits;
	}

	return found_numbers;
}

IntegerArray* Math::sum_of_squares() {
	if (!m_start_set || !m_end_set) {
		throw "Error: Start and End values required";
	}

	IntegerArray *digits, *found_numbers = new IntegerArray();
	int found_size = 0, length = 0, sum = 0;

	// For each value in the arry
	for (int i = 0; i < m_arr->get_size(); i++) {
		// Get the digits of the current integer
		digits = m_arr->get_digits(i);

		// Square each digit
		to_squares(digits);

		// Find the sum of all the values
		sum = sum_of(digits);

		// If the sum is equal to the original value
		if (sum == m_arr->get(i)) {
			// Save the original value to our collection
			found_numbers->add(i);
		}

		delete digits;
	}

	return found_numbers;
}

IntegerArray* Math::to_squares() {
	if (!m_start_set || !m_end_set) {
		throw "Error: Start and End values required";
	}
	// Get a new IntegerArray object
	IntegerArray* squared = new IntegerArray(m_arr->get_size());
	//IntegerArray square_arr(m_arr.get_size());

	// For each value in this array
	for (int i = 0; i < m_arr->get_size(); i++) {
		// Get the value
		int val = m_arr->get(i);
		// Square it
		val = val * val;
		// Save it to the square array
		squared->operator[](i) = val;
	}

	return squared;
}

void Math::to_squares(IntegerArray* arr) {
	// Get the size of the incoming array
	int size = arr->get_size(), val = 0;

	// For each value in the array
	for (int i = 0; i < size; i++) {
		// Get the current value
		val = arr->get(i);

		// Square it
		val = val * val;

		// Save it back to the array
		arr->operator[](i) = val;
	}
}

int Math::sum_of(IntegerArray* const arr) {
	// Get the size of the incoming array
	int size = arr->get_size(), sum = 0;

	// For each value in the array
	for (int i = 0; i < size; i++) {
		// Add it to the sum value
		sum += (*arr)[i];
	}

	return sum;
}

void Math::set_values() {
	if (m_start_set && m_end_set && m_arr != nullptr) {
		int nums = m_end - m_start;

		m_arr->set_size(nums);

		for (int i = 0; i < nums; i++) {
			(*m_arr)[i] = m_start + i;
		}
	}
}