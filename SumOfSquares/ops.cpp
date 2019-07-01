#include "ops.h"
#include <iostream>
#include <ctime>
#include "array_ops.h"

void run_operation(int operation, int start, int end) {
	int *found = nullptr, num_found = 0;
	time_t start_time, end_time;

	// Save the start time
	std::time(&start_time);

	// Print the start message
	std::cout << "Running..." << std::endl;

	// Run the selected operation
	if (operation == SUM_OF_SQUARES) {
		found = sum_of_squares(start, end, num_found);
	}
	else if (operation == SQUARE_OF_SUMS) {
		found = square_of_sums(start, end, num_found);
	}

	// Save the end time
	std::time(&end_time);

	// Print the elapsed time
	std::cout << "Finished!" << std::endl;
	std::cout << "Total time: " << std::difftime(end_time, start_time) << " sec." << std::endl;

	// Print the result of the operation
	if (num_found) {
		std::cout << "Values found: ";
		print_array(found, num_found);
	}
	else {
		std::cout << "No suitable values found in the given range." << std::endl;
	}
}

int* square_of_sums(int start, int end, int &num_found) {
	int *digits, *found_numbers = nullptr, found_size = 0, length = 0, sum = 0, sqr = 0;

	for (int i = start; i <= end; i++) {
		// Get the digits from the number
		digits = get_digits(i, length);

		// Get the sum of the digits
		sum = sum_array(digits, length);

		// Square the sum
		sqr = square(sum);

		if (sqr == i) {
			// If the square is equal to the number, add it to our collection
			found_numbers = grow_array(found_numbers, found_size, found_size + 1);
			found_numbers[found_size++] = i;
		}

		// Deallocate this array of digits
		delete[] digits;
	}

	// Save the total number of values found
	num_found = found_size;

	// Return the array of values
	return found_numbers;
}

int* sum_of_squares(int start, int end, int &num_found) {
	int *digits, *found_numbers = nullptr, found_size = 0, length = 0, sum = 0;

	for (int i = start; i <= end; i++) {
		// Get the digits in the number
		digits = get_digits(i, length);

		// Square each of the digits
		square_array(digits, length);

		// Find the sum of all the values
		sum = sum_array(digits, length);

		// If the sum is the same as the original number, add it to our collection
		if (sum == i) {
			found_numbers = grow_array(found_numbers, found_size, found_size + 1);
			found_size++;

			found_numbers[found_size - 1] = i;
		}

		// Deallocate the array of digits
		delete[] digits;
	}

	// Save the total number of values found
	num_found = found_size;

	// Return the array of values
	return found_numbers;
}