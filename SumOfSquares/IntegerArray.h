#pragma once

class IntegerArray {
public:
	IntegerArray();
	IntegerArray(int size);
	~IntegerArray();
	int& operator[](int index);
	void operator=(IntegerArray right);
	int get_size();
	void set_size(int size);
	void copy(int *arr, int len);
	void add(int val);
	int get(int index);
	IntegerArray* get_digits(int index);
	void reverse();
	int* array();
	static void reverse(int* arr, int len);
	static void copy_array(int *src, int src_len, int *dest, int dest_len);
private:
	int m_size;
	int m_index;
	int* m_arr;

	void deallocate();
};