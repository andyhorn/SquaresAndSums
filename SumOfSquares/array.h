#pragma once

class integerArray {
public:
	integerArray();
	integerArray(int size);
	~integerArray();
	int & operator[](int index);
	void operator=(integerArray right);
	int get_size();
	void set_size(int size);
	void set(int *arr, int len);
	void add(int val);
	int get(int index);
	integerArray get_digits(int index);
	void reverse();
	int* array();
	static void reverse(int* arr, int len);
	static void copy_array(int *src, int src_len, int *dest, int dest_len);
private:
	int m_size;
	int m_index;
	int* m_arr;
};