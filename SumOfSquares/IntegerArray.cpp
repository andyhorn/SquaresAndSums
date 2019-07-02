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

	// Set all values in the array to zero
	for (int i = 0; i < size; i++) {
		m_arr[i] = 0;
	}
}

IntegerArray::~IntegerArray() {
	// If the underlying array exists, delete it
	if (m_arr != nullptr && m_size > 0) {
		delete[] m_arr;
	}
}

int& IntegerArray::operator[](int index) {
	// Get and return a reference to the value at the specified index
	if (index < m_size) {
		return m_arr[index];
	}
	else {
		throw "Error: Argument out of range";
	}
}

void IntegerArray::operator=(IntegerArray right) {
	int size = right.get_size();

	// Delete the current array
	delete[] m_arr;

	// Instantiate a new array of the requested size
	m_arr = new int[size];

	// Deep copy the values into the new array
	for (int i = 0; i < size; i++) {
		int val = right[i];
		m_arr[i] = val;
	}
}

void IntegerArray::copy(int *arr, int len) {
	// Delete the current array
	delete[] m_arr;

	// Instantiate a new array of the same size as the array to be copied
	m_arr = new int[len];

	// Deep copy the values into the new array
	for (int i = 0; i < len; i++) {
		int val = arr[i];
		m_arr[i] = val;
	}
}

int IntegerArray::get_size() {
	return m_size;
}

void IntegerArray::set_size(int size) {
	// If the underlying array hasn't been instantiated,
	// allocate a new array of the requested size
	if (m_arr == nullptr) {
		m_arr = new int[size];
		m_size = size;
	}
	else {
		// Else, create a new array of the requested size
		int *new_arr = new int[size];

		// Copy the contents of the current array into the new array
		copy_array(m_arr, m_size, new_arr, size);

		// Delete the current array
		if (m_size == 1) {
			delete m_arr;
		}
		else {
			delete[] m_arr;
		}

		// Set the new array as the member array
		m_arr = new_arr;
		m_size = size;
	}
}

void IntegerArray::add(int val) {
	// Increment the size of the array
	set_size(m_size + 1);

	// Save the given value to the end
	m_arr[m_size - 1] = val;
}

int IntegerArray::get(int index) {
	// Get the value at the specified index
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

			// Add the ones digit to the array
			int digit = num % 10;
			arr->add(digit);

			// Remove the ones digit from the number
			num /= 10;
		}

		// Add the last digit to the array
		arr->add(num);

		return arr;
	}
	else {
		// If there is only one digit, we don't need to do anything
		// other than saving the digit
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

// Having trouble with this one...
void IntegerArray::reverse(int* arr, int len) {
	// Create a new integer array of the given length
	int *rev_arr = new int[len];

	// For each value
	for (int i = 0; i < len; i++) {
		
		// Get the values, working back from the end
		int val = arr[len - i - 1];

		// Save the values to the new array, beginning at the front
		rev_arr[i] = val;
	}

	// Delete the old array
	delete[] arr;

	// Point the array pointer to the new array
	arr = rev_arr;
}

void IntegerArray::copy_array(int *src, int src_len, int *dest, int dest_len) {
	// Deep copy the source array into the destination array
	for (int i = 0; i < src_len && i < dest_len; i++) {
		int val = src[i];
		dest[i] = val;
	}
}