#pragma once

#include <iostream>

const int MAX_LENGTH = 2056;

void clear_buffer(char* buffer, int size);
int* get_digits(int num, int& length);
int get_size(char* buffer);
int* grow_array(int* arr, int current_size, int desired_size);
void print_array(int* arr, int length);
int* reverse_array(int* arr, int length);
int square(int num);
void square_array(int* arr, int length);
int sum_array(int* arr, int length);