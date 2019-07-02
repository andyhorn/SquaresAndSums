#include "Buffer.h"
#include <iostream>
#include <cctype>

Buffer::Buffer() {
	m_buffer = new char[MAX_CAPACITY];
	m_capacity = MAX_CAPACITY;
}

Buffer::Buffer(int capacity) {
	m_buffer = new char[capacity];
	m_capacity = capacity;
}

Buffer::~Buffer() {
	delete[] m_buffer;
}

void Buffer::read_line() {
	std::cin >> m_buffer;
	m_used_space = get_length();
}

void Buffer::clear() {
	for (int i = 0; i < m_capacity; i++) {
		m_buffer[i] = '\0';
	}

	m_used_space = 0;
}

int Buffer::get_capacity() {
	return m_capacity;
}

int Buffer::get_length() {
	int len = 0;

	while (m_buffer[len] != '\0' && len < m_capacity) {
		len++;
	}

	return len;
}

bool Buffer::is_number() {
	bool is_num = true;

	for (int i = 0; i < m_used_space; i++) {
		if (!std::isdigit(m_buffer[i])) {
			is_num = false;
			break;
		}
	}

	return is_num;
}

int Buffer::to_int() {
	if (is_number()) {
		int val = std::atoi(m_buffer);
		return val;
	}
	else {
		throw "Error: Invalid argument";
	}
}