#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include "array.h"
#include "ops.h"

#define BUFFER_LENGTH 512

bool get_nums(int &start, int &end);
bool is_number(char* buffer);

int main() {
	int start = 0, end = 0, *found = nullptr, num_found = 0;

	// Get the start and end values, then, if they are valid, proceed
	if (!get_nums(start, end)) {
		std::cout << "Invalid input. Try again." << std::endl;
		return -1;
	}
	else {
		std::cout << std::endl;
		run_operation(SUM_OF_SQUARES, start, end);

		std::cout << std::endl;
		run_operation(SQUARE_OF_SUMS, start, end);
	}

	return 0;
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