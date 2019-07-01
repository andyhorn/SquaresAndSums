#include "array.h"

integerArray::integerArray() {
	m_size = 0;
	m_index = 0;
	m_arr = nullptr;
}

integerArray::integerArray(int size) {
	m_size = size;
	m_index = 0;
	m_arr = new int[size];

	for (int i = 0; i < size; i++) {
		m_arr[i] = 0;
	}
}

integerArray::~integerArray() {
	delete[] m_arr;
}

int& integerArray::operator[](int index) {
	if (index < m_size) {
		return m_arr[index];
	}
	else {
		throw "Error: Argument out of range";
	}
}

void integerArray::operator=(integerArray right) {
	int size = right.get_size();

	delete[] m_arr;
	m_arr = new int[size];

	for (int i = 0; i < size; i++) {
		m_arr[i] = right[i];
	}
}

void integerArray::set(int *arr, int len) {
	delete[] m_arr;
	m_arr = new int[len];

	for (int i = 0; i < len; i++) {
		m_arr[i] = arr[i];
	}
}

int integerArray::get_size() {
	return m_size;
}

void integerArray::set_size(int size) {
	int *new_arr = new int[size];
	copy_array(m_arr, m_size, new_arr, size);

	delete[] m_arr;
	m_arr = new_arr;
	m_size = size;
}

void integerArray::add(int val) {
	set_size(m_size + 1);
	m_arr[m_size - 1] = val;
}

int integerArray::get(int index) {
	if (index < m_size) {
		return m_arr[index];
	}
	else {
		throw "Error: Argument out of range";
	}
}


integerArray integerArray::get_digits(int index) {
	integerArray arr;
	int size = 0;

	if (index >= m_size) {
		throw "Error: Argument out of range";
	}

	int num = m_arr[index];

	// If there is more than one digit
	if (num > 9) {

		// Loop through the number, removing the end digit
		// with each pass and adding it to an array of digits
		while (num >= 10) {

			// Grow the integer array by one
			arr.set_size(size + 1);
			size += 1;

			// Add the ones digit to the array
			int digit = num % 10;
			arr[size - 1] = digit;

			// Remove the ones digit from the number
			num /= 10;
		}

		// Grow the array one last time
		arr.set_size(size + 1);
		size += 1;

		// Add the last digit to the array
		arr[size - 1] = num;

		// Reverse the array (since it was built in reverse order)
		arr.reverse();
		return arr;
	}
	else {
		// If there is only one digit, we don't need to do anything
		// other than saving the digit to an array of length 1
		arr.add(num);
		return arr;
	}
}

int* integerArray::array() {
	return m_arr;
}

void integerArray::reverse() {
	reverse(m_arr, m_size);
}

void integerArray::reverse(int* arr, int len) {
	int *rev_arr = new int[len];

	for (int i = 0; i < len; i++) {
		rev_arr[len - (i + 1)] = arr[i];
	}

	delete[] arr;
	arr = rev_arr;
}

void integerArray::copy_array(int *src, int src_len, int *dest, int dest_len) {
	for (int i = 0; i < src_len && i < dest_len; i++) {
		dest[i] = src[i];
	}
}