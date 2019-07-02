#include "IntegerArray.h"

IntegerArray::IntegerArray() {
	m_size = 0;
	m_index = 0;
	m_arr = nullptr;
}

IntegerArray::IntegerArray(int size) {
	m_size = size;
	m_index = 0;
	m_arr = new int[size];

	for (int i = 0; i < size; i++) {
		m_arr[i] = 0;
	}
}

IntegerArray::~IntegerArray() {
	if (m_arr != nullptr && m_size > 0) {
		delete[] m_arr;
	}
}

int& IntegerArray::operator[](int index) {
	if (index < m_size) {
		return m_arr[index];
	}
	else {
		throw "Error: Argument out of range";
	}
}

void IntegerArray::operator=(IntegerArray right) {
	int size = right.get_size();

	delete[] m_arr;
	m_arr = new int[size];

	for (int i = 0; i < size; i++) {
		int val = right[i];
		m_arr[i] = val;
	}
}

void IntegerArray::copy(int *arr, int len) {
	delete[] m_arr;
	m_arr = new int[len];

	for (int i = 0; i < len; i++) {
		int val = arr[i];
		m_arr[i] = val;
	}
}

int IntegerArray::get_size() {
	return m_size;
}

void IntegerArray::set_size(int size) {
	if (m_arr == nullptr) {
		m_arr = new int[size];
		m_size = size;
	}
	else {
		int *new_arr = new int[size];
		copy_array(m_arr, m_size, new_arr, size);

		if (m_size == 1) {
			delete m_arr;
		}
		else {
			delete[] m_arr;
		}

		m_arr = new_arr;
		m_size = size;
	}
}

void IntegerArray::add(int val) {
	set_size(m_size + 1);
	m_arr[m_size - 1] = val;
}

int IntegerArray::get(int index) {
	if (index < m_size) {
		return m_arr[index];
	}
	else {
		throw "Error: Argument out of range";
	}
}


IntegerArray* IntegerArray::get_digits(int index) {
	int size = 0;
	IntegerArray* arr = new IntegerArray();

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
			//arr->set_size(size + 1);
			//size += 1;

			// Add the ones digit to the array
			int digit = num % 10;
			//arr[size - 1] = digit;
			arr->add(digit);

			// Remove the ones digit from the number
			num /= 10;
		}

		// Grow the array one last time
		//arr->set_size(size + 1);
		//size += 1;

		// Add the last digit to the array
		//arr[size - 1] = num;
		arr->add(num);

		// Reverse the array (since it was built in reverse order)
		//arr->reverse();
		return arr;
	}
	else {
		// If there is only one digit, we don't need to do anything
		// other than saving the digit to an array of length 1
		arr->add(num);
		return arr;
	}
}

int* IntegerArray::array() {
	return m_arr;
}

void IntegerArray::reverse() {
	reverse(m_arr, m_size);
}

void IntegerArray::reverse(int* arr, int len) {
	int *rev_arr = new int[len];

	for (int i = 0; i < len; i++) {
		int val = arr[len - i - 1];
		rev_arr[i] = val;
	}

	delete[] arr;
	arr = rev_arr;
}

void IntegerArray::copy_array(int *src, int src_len, int *dest, int dest_len) {
	for (int i = 0; i < src_len && i < dest_len; i++) {
		int val = src[i];
		dest[i] = val;
	}
}