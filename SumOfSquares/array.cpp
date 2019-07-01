#include "array.h"

void clear_buffer(char* buffer, int size) {
	// Loop through the entire array and set all values to the null terminator
	for (int i = 0; i < size; i++) {
		buffer[i] = '\0';
	}
}

int get_size(char* buffer) {
	int size = 0;

	// Loop through the array until a null-terminator is located
	// or the MAX_LENGTH value is reached
	for (int i = 0; i < MAX_LENGTH; i++) {

		// If the current value is not a null-terminator
		// increment the counter
		if (buffer[i] != '\0') {
			size++;
		}
		else {
			break;
		}
	}

	return size;
}

int* get_digits(int num, int &length) {
	int* arr = nullptr;
	int size = 0;

	// If there is more than one digit
	if (num > 9) {

		// Loop through the number, removing the end digit
		// with each pass and adding it to an array of digits
		while (num >= 10) {

			// Grow the integer array by one
			arr = grow_array(arr, size, size + 1);
			size += 1;

			// Add the ones digit to the array
			int digit = num % 10;
			arr[size - 1] = digit;

			// Remove the ones digit from the number
			num /= 10;
		}

		// Grow the array one last time
		arr = grow_array(arr, size, size + 1);
		size += 1;

		// Add the last digit to the array
		arr[size - 1] = num;

		// Save the final size
		length = size;

		// Reverse the array (since it was built in reverse order)
		arr = reverse_array(arr, length);
		return arr;
	}
	else {
		// If there is only one digit, we don't need to do anything
		// other than saving the digit to an array of length 1
		arr = new int[1];
		arr[0] = num;
		length = 1;
		return arr;
	}
}

int* grow_array(int* arr, int current_size, int desired_size) {
	// Create a new array of the desired length
	int* new_array = new int[desired_size];

	// Copy the values from the existing array to the new array
	for (int i = 0; i < current_size; i++) {
		new_array[i] = arr[i];
	}

	// Deallocate the previous array
	delete[] arr;

	// Return the new array
	return new_array;
}

int* reverse_array(int* arr, int size) {
	// Create a new, empty array
	int* new_array = new int[size];

	// Loop through each array, beginning at the end
	// of the previous array and the front of the new array
	// placing values in reverse order
	for (int i = size - 1, j = 0; i >= 0;) {
		new_array[j++] = arr[i--];
	}

	// Deallocate the old array
	delete[] arr;

	// Return the new array
	return new_array;
}

int square(int num) {
	return num * num;
}

void square_array(int* arr, int length) {
	// Loop through the array and save the square of the value
	for (int i = 0; i < length; i++) {
		arr[i] = square(arr[i]);
	}
}

int sum_array(int* arr, int length) {
	int sum = 0;
	
	// Loop through the array and sum up its values
	for (int i = 0; i < length; i++) {
		sum += arr[i];
	}

	// Return the total sum
	return sum;
}

void print_array(int* arr, int length) {
	std::cout << "[";;
	for (int i = 0; i < length; i++) {
		if (i < length - 1) {
			std::cout << arr[i] << ", ";
		}
		else {
			std::cout << arr[i] << "]";
		}
	}
	std::cout << std::endl;
}