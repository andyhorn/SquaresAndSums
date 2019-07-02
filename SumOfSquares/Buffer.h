#pragma once

const int MAX_CAPACITY = 1024;

class Buffer {
public:
	Buffer();
	Buffer(int size);
	~Buffer();

	void read_line();
	void clear();
	int get_capacity();
	int get_length();
	bool is_number();
	int to_int();
private:
	int m_capacity;
	int m_used_space;
	char* m_buffer;
};