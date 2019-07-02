#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include "Math.h"

#define BUFFER_LENGTH 512

bool get_nums(int &start, int &end);
bool is_number(char* buffer);
void print_array(IntegerArray arr);
int get_size(char* buffer);
void clear_buffer(char* buffer, int size);

int main() {
	int start = 0, end = 0, *found = nullptr, num_found = 0;
	Math math;
	IntegerArray* arr;

	// Get the start and end values, then, if they are valid, proceed
	if (!get_nums(start, end)) {
		std::cout << "Invalid input. Try again." << std::endl;
		return -1;
	}
	else {
		// If the values are valid numbers, 
		// set the start and end values in the math object.
		math.set_start(start);
		math.set_end(end);
		std::cout << std::endl;

		// Announce the start of the sum of squares procedure
		std::cout << "Sum of Squares:" << std::endl;

		// Get the sum of squares results
		arr = math.sum_of_squares();

		// If the array has results, print them
		if (arr->get_size()) {
			print_array(*arr);
		}
		// Else, print the error message
		else {
			std::cout << "No valid values found in given range.\n" << std::endl;
		}

		// Announce the square of sums procedure
		std::cout << "Square of Sums:" << std::endl;

		// Get the square of sums results
		arr = math.square_of_sums();

		// If the array has results, print them
		if (arr->get_size()) {
			print_array(*arr);
		}
		// Else, print the error message
		else {
			std::cout << "No valid values found in given range.\n" << std::endl;
		}
	}

	return 0;
}

void print_array(IntegerArray arr) {
	// Verify the array has values to print
	if (arr.get_size()) {
		// Print the size of the array
		std::cout << "Total Values: " << arr.get_size() << std::endl;
		std::cout << "List of Values: [";

		// Print each value in the array, followed by a comma and a space
		for (int i = 0; i < arr.get_size() - 1; i++) {
			std::cout << arr[i] << ", ";
		}

		// Print the last value followed by a closing bracket
		std::cout << arr[arr.get_size() - 1] << "]" << std::endl;
	}
}

bool get_nums(int &start, int &end) {
	// Make a character array buffer
	char *buffer = new char[BUFFER_LENGTH];

	// Get the beginning value
	std::cout << "Beginning of range: ";
	std::cin >> buffer;

	// Verify the value is an integer
	if (!is_number(buffer)) {
		std::cout << "Invalid input, try again.";
		return false;
	}

	// Convert the character string to an integer
	start = std::atoi(buffer);

	// Clear the buffer
	clear_buffer(buffer, BUFFER_LENGTH);

	// Get the end value
	std::cout << "End of range: ";
	std::cin >> buffer;

	// Verify the value is an integer
	if (!is_number(buffer)) {
		std::cout << "Invalid input, try again.";
		return false;
	}

	// Convert the character string to an integer
	end = std::atoi(buffer);

	// Deallocate the buffer space
	delete[] buffer;

	// Announce the values retrieved
	std::cout << "\nBeginning value: " << start << "\tEnding value: " << end << std::endl;

	return true;
}

bool is_number(char* buffer) {
	bool isNum = true;

	// Get the size of the buffer
	int size = get_size(buffer);

	// Loop through the values
	for (int i = 0; i < size; i++) {

		// If the current value is not a valid digit,
		// set the flag and stop the loop
		if (!std::isdigit(buffer[i])) {
			isNum = false;
			break;
		}
	}

	return isNum;
}

int get_size(char* buffer) {
	int size = 0;

	// Move through the buffer until a null-terminator is found,
	// count the number of steps through the array.
	while (buffer[size] != '\0') { size++; }

	return size;
}

void clear_buffer(char* buffer, int size) {
	// Set each index in the array equal to the null terminator
	for (int i = 0; i < size; i++) {
		buffer[i] = '\0';
	}
}