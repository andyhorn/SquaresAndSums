#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include "array_ops.h"
#include "ops.h"
#include "Math.h"

#define BUFFER_LENGTH 512

bool get_nums(int &start, int &end);
bool is_number(char* buffer);
void print_array(integerArray arr);

int main() {
	int start = 0, end = 0, *found = nullptr, num_found = 0;
	math m;
	integerArray arr;

	// Get the start and end values, then, if they are valid, proceed
	if (!get_nums(start, end)) {
		std::cout << "Invalid input. Try again." << std::endl;
		return -1;
	}
	else {
		m.set_start(start);
		m.set_end(end);
		std::cout << std::endl;
		arr = m.sum_of_squares();
		//run_operation(SUM_OF_SQUARES, start, end);
		print_array(arr);

		arr = m.square_of_sums();
		print_array(arr);
		//run_operation(SQUARE_OF_SUMS, start, end);
	}

	return 0;
}

void print_array(integerArray arr) {
	if (arr.get_size()) {
		std::cout << "Total Values: " << arr.get_size() << std::endl;
		std::cout << "List of Values: [";
		for (int i = 0; i < arr.get_size() - 1; i++) {
			std::cout << arr[i] << ", ";
		}
		std::cout << arr[arr.get_size() - 1] << "]" << std::endl;
	}

	std::cout << std::endl;
}

bool get_nums(int &start, int &end) {
	char *buffer = new char[BUFFER_LENGTH];

	std::cout << "Beginning of range: ";
	std::cin >> buffer;

	if (!is_number(buffer)) {
		std::cout << "Invalid input, try again.";
		return false;
	}

	start = std::atoi(buffer);

	clear_buffer(buffer, BUFFER_LENGTH);

	std::cout << "End of range: ";
	std::cin >> buffer;

	if (!is_number(buffer)) {
		std::cout << "Invalid input, try again.";
		return false;
	}

	end = std::atoi(buffer);
	delete[] buffer;

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