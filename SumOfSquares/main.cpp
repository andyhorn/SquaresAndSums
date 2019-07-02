#include <iostream>
#include "Math.h"
#include "Time.h"
#include "Buffer.h"

bool get_nums(int &start, int &end);
void print_array(IntegerArray* arr);

int main() {
	int start = 0, end = 0;
	Math math;
	Time timer;
	IntegerArray* arr;
	
	// Get the start and end values and check if they are valid
	if (!get_nums(start, end)) {
		std::cout << "Invalid input. Try again." << std::endl;
		return -1;
	}
	else {
		// Set the start and end values in the math object.
		math.set_start(start);
		math.set_end(end);
		std::cout << std::endl;

		// Announce the start of the sum of squares procedure
		std::cout << "Running Sum of Squares..." << std::endl;

		// Start the timer
		timer.start();

		// Get the sum of squares results
		arr = math.sum_of_squares();

		// End the timer
		timer.end();

		// Print the elapsed time
		std::cout << "Elapsed time: " << timer.get_elapsed() << " ms." << std::endl;

		// If the array has results, print them
		if (arr->get_size()) {
			print_array(arr);
		}
		// Else, print the error message
		else {
			std::cout << "No valid values found in given range.\n" << std::endl;
		}

		// Announce the square of sums procedure
		std::cout << "\nRunning Square of Sums..." << std::endl;

		// Start the timer
		timer.start();

		// Get the square of sums results
		arr = math.square_of_sums();

		// End the timer
		timer.end();

		// Print the elapsed time
		std::cout << "Elapsed time: " << timer.get_elapsed() << " ms." << std::endl;

		// If the array has results, print them
		if (arr->get_size()) {
			print_array(arr);
		}
		// Else, print the error message
		else {
			std::cout << "No valid values found in given range.\n" << std::endl;
		}
	}

	return 0;
}

void print_array(IntegerArray* arr) {
	// Verify the array has values to print
	int size = arr->get_size();

	if (size) {
		// Print the size of the array
		std::cout << "Total Values: " << size << std::endl;
		std::cout << "List of Values: [";

		// Print each value in the array, followed by a comma and a space
		for (int i = 0; i < size - 1; i++) {
			std::cout << (*arr)[i] << ", ";
		}

		// Print the last value followed by a closing bracket
		std::cout << (*arr)[size - 1] << "]" << std::endl;
	}
}

bool get_nums(int &start, int &end) {
	// Get a buffer object
	Buffer buf;

	// Get the beginning value
	std::cout << "Beginning of range: ";
	buf.read_line();

	// Verify the value is an integer
	if (!buf.is_number()) {
		std::cout << "Invalid input, try again.";
		return false;
	}

	// Convert the character string to an integer
	start = buf.to_int();

	// Clear the buffer
	buf.clear();

	// Get the end value
	std::cout << "End of range: ";
	buf.read_line();

	// Verify the value is an integer
	if (!buf.is_number()) {
		std::cout << "Invalid input, try again.";
		return false;
	}

	// Convert the character string to an integer
	end = buf.to_int();

	// Announce the values retrieved
	std::cout << "\nBeginning value: " << start << "\tEnding value: " << end << std::endl;

	return true;
}