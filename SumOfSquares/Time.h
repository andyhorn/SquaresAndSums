#pragma once

#include <chrono>

class Time {
public:
	Time();
	~Time();
	int64_t ticks();
	void start();
	void end();
	int64_t get_elapsed();
private:
	int64_t m_start_time;
	int64_t m_end_time;
};