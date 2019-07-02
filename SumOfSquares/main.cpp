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
		math.set_start(start);
		math.set_end(end);
		std::cout << std::endl;

		std::cout << "Sum of Squares:" << std::endl;
		arr = math.sum_of_squares();
		print_array(*arr);

		std::cout << "Square of Sums:" << std::endl;
		arr = math.square_of_sums();
		print_array(*arr);
	}

	return 0;
}

void print_array(IntegerArray arr) {
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

int get_size(char* buffer) {
	int size = 0;

	while (buffer[size] != '\0') { size++; }

	return size;
}

void clear_buffer(char* buffer, int size) {
	for (int i = 0; i < size; i++) {
		buffer[i] = '\0';
	}
}